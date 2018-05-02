#ifndef XMLTREE_HPP
#define XMLTREE_HPP

#include <QList>
#include <QMap>
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

typedef QMap< QString, QString > Attr;

class XMLTag;


class XMLTag {

	public:

		explicit
		XMLTag( QString const & p_name, Attr const & p_atrributes, XMLTag * p_parent ) :
		__parent( p_parent ),
		__name( p_name ),
		__attributes( p_atrributes ) {

		}

		explicit
		XMLTag( QString const & p_name, Attr const & p_atrributes, QString const & p_data, XMLTag * p_parent ) :
		__parent( p_parent ),
		__name( p_name ),
		__data( p_data ),
		__attributes( p_atrributes ) {

		}

		virtual
		~XMLTag( ) {

			delete __parent;
		}

	protected:

		XMLTag
		* __parent;

		QString
		__name,
		__data;

		Attr
		__attributes;

		QList< XMLTag * >
		__children;

	public:

		XMLTag
		* parent( ) const {

			return __parent;
		}

		QString
		name( ) const {

			return __name;
		}

		Attr
		attr( ) const {

			return __attributes;
		}

		void
		setName( QString const & p_name ) {

			__name = p_name;
		}

		void
		setAttr( QString const & p_attrKey, QString const & p_attrVal ) {

			__attributes[ p_attrKey ] = p_attrVal;
		}

		QString
		attr( QString const & p_attrKey ) {

			auto
			found = __attributes.find( p_attrKey );

			if( found != __attributes.cend( ) ) {

				return __attributes[ p_attrKey ];
			}

			return QString( );
		}

		XMLTag
		* addTag( QString const & p_name, Attr const & p_attr ) {

			XMLTag
			* nt = new XMLTag( p_name, p_attr, this );

			__children.append( nt );

			return nt;
		}

		XMLTag
		* addLeave( QString const & p_name, Attr const & p_attr, QString const & p_data ) {

			XMLTag
			* nl = new XMLTag( p_name, p_attr, p_data, this );

			__children.append( nl );

			return nl;
		}

		QList< XMLTag * >
		children( ) const {

			return __children;
		}

		QString
		data( ) const {

			return __data;
		}

		void
		delChild( XMLTag * p_xmlNode ) {

			auto
			c = __children.begin( );

			while( c != __children.end( ) ) {

				if( *c == p_xmlNode ) {

					delete *c;

					__children.erase( c );
				}
			}
		}

		void
		write( QXmlStreamWriter & p_sw ) {

			if( __children.isEmpty( ) && __data.isNull( ) ) {

				return;
			}

			QXmlStreamAttributes
			xmlAttr;

			for( auto s = attr( ).cbegin( ); s != attr( ).cend( ); ++ s ) {

				xmlAttr.append( s.key( ), s.value( ) );
			}

			p_sw.writeStartElement( __name );

			p_sw.writeAttributes( xmlAttr );

			if( !__children.isEmpty( ) ) {

				for( QList< XMLTag * >::const_iterator i = __children.cbegin( ); i != __children.cend( ); ++ i ) {

					( *i )->write( p_sw );
				}
			}
			else {

				p_sw.writeCharacters( __data );
			}

			p_sw.writeEndElement( );
		}
};

class XMLTree {

	public:

		XMLTree( ) {

			__root = nullptr;
			__curr = __root;

		}

		~XMLTree( ) {

			delete __root;
		}

	private:

		XMLTag
		* __root,
		* __curr;

		bool
		__writeAll( QXmlStreamWriter & p_sw ) {

			if( ! __root ) {

				return false;
			}

			resetPointer( );

			p_sw.setAutoFormatting( true );

			p_sw.writeStartDocument( "1.0", true );

            p_sw.writeDefaultNamespace( "https://imise.uni-leipzig.de" );

			p_sw.writeDTD( "<!DOCTYPE fract-wrapper-config>" );

			__root->write( p_sw );

			p_sw.writeEndDocument( );

			return true;
		}

	public:

        void
        clear( ) {

            delete __root;

            __root = nullptr;
        }

		bool
		load( QString const & p_filename ) {

			delete __root;

			QFile
			xmlFile( p_filename );

			if( ! xmlFile.open( QIODevice::ReadOnly | QIODevice::Text ) ) {

				return false;
			}

			QXmlStreamReader
			xmlSR( &xmlFile );

            if( xmlSR.readNextStartElement( ) ) {

                QXmlStreamAttributes
                qattr = mlSR.attributes( );

                Attr
                attr;

                __root = new XMLTag( xmlSR.name( ) );

                for( int i = 0; i < attr.size( ); ++ i ) {

                    attr[ qattr.at( i ).name( ) ] = qattr.at( i ).value( );
                }




            }

			return false;
		}

		bool
		save( QString const & p_filename ) {

			QFile
			xmlFile( p_filename );

			if( ! xmlFile.open( QIODevice::WriteOnly | QIODevice::Text ) ) {

				return false;
			}

			QXmlStreamWriter
			xmlSR( &xmlFile );

			bool
			ret = __writeAll( xmlSR );

			xmlFile.close( );

			return ret;
		}

		QString
		toStr( ) {

			QString
			text;

			QXmlStreamWriter
			xmlSR( &text );

			__writeAll( xmlSR );

			return text;
		}

		void
		addTag( QString const & p_name, Attr const & p_attr ) {

			if( ! __root ) {

				__curr  = new XMLTag( p_name, p_attr, nullptr );
				__root = __curr;

				return;
			}

			__curr = __curr->addTag( p_name, p_attr );
		}

		void
		addTag( QString const & p_name ) {

			addTag( p_name, Attr( ) );
		}

		void
		addLeave( QString const & p_name, Attr const & p_attr, QString const & p_data ) {

			if( ! __root ) {

				__curr  = new XMLTag( p_name, p_attr, nullptr );
				__root = __curr;

				return;
			}

			__curr->addLeave( p_name, p_attr, p_data );
		}

		void
		addLeave( QString const & p_name, QString const & p_data ) {

			addLeave( p_name, Attr( ), p_data );
		}

		void
		up( ) {

			__curr = __curr->parent( );
		}

		void
		resetPointer( ) {

			__curr = __root;
		}
};
#endif // XMLTREE_HPP
