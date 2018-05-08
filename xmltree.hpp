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

//typedef QMap< QString, QString > Attr;
typedef QXmlStreamAttribute  Attr;
typedef QXmlStreamAttributes Attrs;
typedef QXmlStreamNamespaceDeclaration  NSpace;
typedef QXmlStreamNamespaceDeclarations NSpaces;

class XMLTag;

class XMLTag {

	public:

		explicit
		XMLTag( ) :
		__parent( nullptr ),
		__name( ),
		__data( ),
		__attr( ),
		__nspace( ) {

		}

		explicit
		XMLTag( QString const & p_name ) :
		__parent( nullptr ),
		__name( p_name ),
		__data( ),
		__attr( ),
		__nspace( ) {

		}

		explicit
		XMLTag( QString const & p_name, XMLTag * p_parent ) :
		__parent( p_parent ),
		__name( p_name ),
		__data( ),
		__attr( ),
		__nspace( ) {

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

/*		Attr
		__attributes;
*/
		Attrs
		__attr;

		NSpaces
		__nspace;

		QList< XMLTag * >
		__children;

	public:

		XMLTag
		* parent( ) const {

			return __parent;
		}

		void
		decouple( ) {

			__children.clear( );
		}

		QString
		name( ) const {

			return __name;
		}

		Attrs
		attrs( ) const {

			return __attr;
		}

		NSpaces
		nspace( ) const {

			return __nspace;
		}

		void
		setName( QString const & p_name ) {

			__name = p_name;
		}

		void
		setAttrs( QXmlStreamAttributes const & p_attrs ) {

			__attr = p_attrs;
		}

		void
		setAttr( QXmlStreamAttribute const & p_attr ) {

			__attr << p_attr;
		}

		void
		setNSpace( QXmlStreamNamespaceDeclarations const & p_nsd ) {

			__nspace = p_nsd;
		}

		void
		setData( QString const & p_data ) {

			__data = p_data;
		}

		XMLTag
		* addTag( QString const & p_name ) {

			XMLTag
			* nt = new XMLTag( p_name, this );

			__children.append( nt );

			return nt;
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
		read( QXmlStreamReader & p_sr ) {

			if( p_sr.atEnd( ) ) {

				return;
			}

			QXmlStreamReader::TokenType
			token = p_sr.readNext( );

			QXmlStreamAttributes
			at = p_sr.attributes( );

			QXmlStreamNamespaceDeclarations
			ns = p_sr.namespaceDeclarations( );

			QString
			nm = p_sr.name( ).toString( ),
			ch = p_sr.text( ).toString( ).trimmed( );

			switch( token ) {

				case QXmlStreamReader::NoToken : {

					std::cout << "[No Token]";

					break;
				}

				case QXmlStreamReader::Invalid : {

					std::cout << "[Invalid]";

					break;
				}

				case QXmlStreamReader::StartDocument : {

					std::cout << "[StartDocument]";

					break;
				}

				case QXmlStreamReader::EndDocument : {

					std::cout << "[EndDocument]";

					return;
				}

				case QXmlStreamReader::StartElement : {

					std::cout << "[StartElement]";

					if( ! nm.isEmpty( ) ) {

						XMLTag
						* xmlTag = new XMLTag( nm, this );

						xmlTag->setAttrs( at );
						xmlTag->setNSpace( ns );
						xmlTag->setData( ch );
						xmlTag->read( p_sr );
						__children.append( xmlTag );
					}


					break;
				}

				case QXmlStreamReader::EndElement : {

					std::cout << "[EndElement]";

					return;
				}

				case QXmlStreamReader::Characters : {

					std::cout << "[Characters]";

					setData( ch );

					break;
				}

				case QXmlStreamReader::Comment : {

					std::cout << "[Comment]";

					break;
				}

				case QXmlStreamReader::DTD : {

					setName( "DTD" );
					setData( ch );

					std::cout << "[DTD]";

					break;
				}

				case QXmlStreamReader::EntityReference : {

					std::cout << "[EntityReference]";
					break;
				}

				case QXmlStreamReader::ProcessingInstruction : {

					std::cout << "[ProcessingInstruction]";
					break;
				}

				default : {

					std::cout << "[default]";
					break;
				}
			}

			if( ! ch.isEmpty( ) ) std::cout << ch.toStdString( );

			if( ! nm.isEmpty( ) ) std::cout << "<" << nm.toStdString( ) << ">";

			read( p_sr );
		}

		void
		write( QXmlStreamWriter & p_sw ) {

/*			if( __children.isEmpty( ) && __data.isNull( ) ) {

				return;
			}*/
/*
			QXmlStreamAttributes
			xmlAttr;

			for( auto s = attrs( ).cbegin( ); s != attrs( ).cend( ); ++ s ) {

				xmlAttr.append( s.key( ), s.value( ) );
			}
*/
			p_sw.writeStartElement( __name );

			if( ! __nspace.isEmpty( ) ) {

				for( int i = 0; i < __nspace.length( ); ++ i ) {

					p_sw.writeNamespace( __nspace.at( i ).namespaceUri( ).toString( ), __nspace.at( i ).prefix( ).toString( ) );
				}
			}

			if( ! __attr.isEmpty( ) ) {

				p_sw.writeAttributes( __attr );
			}

			if( !__children.isEmpty( ) ) {

				for( QList< XMLTag * >::const_iterator i = __children.cbegin( ); i != __children.cend( ); ++ i ) {

					( *i )->write( p_sw );
				}
			}
			else {

				if( ! __data.isEmpty( ) ) {

					p_sw.writeCharacters( __data );
				}
			}

			p_sw.writeEndElement( );
		}
};

class XMLTree {

	public:

		XMLTree( ) {

			__root = nullptr;
			__curr = __root;
			__dtd = "<!DOCTYPE xml>";
			__nspc = "https://github.com/samuelohterion";
		}

		~XMLTree( ) {

			delete __root;
		}

	private:

		XMLTag
		* __root,
		* __curr;

		QString
		__dtd,
		__nspc;

		bool
		__writeAll( QXmlStreamWriter & p_sw ) {

			if( ! __root ) {

				return false;
			}

			resetPointer( );

			p_sw.setAutoFormatting( true );

			p_sw.writeStartDocument( "1.0", true );

			p_sw.writeDefaultNamespace( "https://samuelohterion.github.io/XMLTree" );

			p_sw.writeNamespace( __nspc );

			p_sw.writeDTD( __dtd );

			__root->write( p_sw );

			p_sw.writeEndDocument( );

			return true;
		}

	public:

		XMLTag
		* curr( ) const {

			return __curr;
		}

		void
		clear( ) {

			delete __root;

			__root = nullptr;
		}

		bool
		load( QString const & p_filename ) {

			delete __root;

			__root = nullptr;

			QFile
			xmlFile( p_filename );

			if( ! xmlFile.open( QIODevice::ReadOnly | QIODevice::Text ) ) {

				return false;
			}

			QXmlStreamReader
			xmlSR( &xmlFile );

			XMLTag
			* xmlTag = new XMLTag( );

			xmlTag->read( xmlSR );

			xmlFile.close( );

			if( true || xmlTag->name( ) == "DTD" ) {

				__dtd = xmlTag->data( );

				__root = xmlTag->children( ).at( 0 );

				xmlTag->decouple( );
			}
			else {

				__root = xmlTag;
			}



/*
			if( xmlSR.readNextStartElement( ) ) {

				switch( xmlSR.tokenType( ) ) {

					case NoToken : {

						break;
					}

					case Invalid : {

						break;
					}

					case StartDocument : {

						break;
					}

					case EndDocument : {

						break;
					}

					case StartElement : {

						break;
					}

					case EndElement : {

						break;
					}

					case Characters : {

						break;
					}

					case Comment : {

						break;
					}

					case DTD : {

						break;
					}

					case EntityReference : {

						break;
					}

					case ProcessingInstruction : {

						break;
					}

					default : {

						break;
					}
				}


				QXmlStreamAttributes
				qattr = xmlSR.attributes( );

				Attr
				attr;
				__root = new XMLTag( xmlSR.name( ).toString( ) );

				for( int i = 0; i < attr.size( ); ++ i ) {

					attr[ qattr.at( i ).name( ).toString( ) ] = qattr.at( i ).value( ).toString( );
				}

			}
*/
			return true;
		}

		void
		setDTD( QString const & p_dtd ) {

			__dtd = QString( "<!DOCTYPE %1>" ).arg( p_dtd );
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

		XMLTree
		& addTag( QString const & p_name ) {

			if( ! __root ) {

				__curr  = new XMLTag( p_name, nullptr );
				__root = __curr;

				return *this;
			}

			__curr = __curr->addTag( p_name );

			return *this;
		}

		XMLTree
		& tag( QString const & p_name ) {

			return addTag( p_name );
		}

		XMLTree
		& setText( QString const & p_data ) {

			if( __curr ) {

				__curr->setData( p_data );
			}

			return *this;
		}

		XMLTree
		& txt( QString const & p_data ) {

			return setText( p_data );
		}

		XMLTree
		& setAttr( Attrs const & p_xmlsa ) {

			if( __curr ) {

				__curr->setAttrs( p_xmlsa );
			}

			return *this;
		}

		XMLTree
		& att( QString const & p_key, QString const & p_value ) {

			__curr->setAttr( Attr( p_key, p_value ) );

			return *this;
		}

		XMLTree
		& setNSpace( NSpaces const & p_nsd ) {

			if( __curr ) {

				__curr->setNSpace( p_nsd );
			}

			return *this;
		}

		XMLTree
		& nspc( NSpaces const & p_nsd ) {

			return setNSpace( p_nsd );
		}

/*		void
		addTagWithText( QString const & p_name, Attr const & p_attr, QString const & p_data ) {

			if( ! __root ) {

				__curr  = new XMLTag( p_name, p_attr, p_data, nullptr );
				__root = __curr;

				return;
			}

			__curr->addTextTag( p_name, p_attr, p_data );
		}

		void
		addTagWithText( QString const & p_name, QString const & p_data ) {

			addTagWithText( p_name, Attr( ), p_data );
		}
*/
		XMLTree
		& up( int p_steps = 1 ) {

			while( p_steps -- ) {

				__curr = __curr->parent( );
			}

			return *this;
		}

		XMLTree
		& gat( int p_steps = 1 ) {

			return up( p_steps );
		}

		XMLTree
		& resetPointer( ) {

			__curr = __root;

			return *this;
		}

		XMLTree
		& rp( ) {

			return resetPointer( );
		}

		XMLTree
		& in( QString const & p_name, int p_id = 0 ) {

			for( auto it : __curr->children( ) ) {

				if( it->name( ) == p_name && p_id -- <= 0 ) {

					__curr = it;

					break;
				}
			}

			return *this;
		}

};
#endif // XMLTREE_HPP
