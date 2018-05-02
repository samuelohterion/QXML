#include <iostream>
#include <QCoreApplication>
#include "xmltree.hpp"

int
main( int p_argc, char * p_argv[ ] ) {

//	QCoreApplication
//	app( p_argc, p_argv );

	XMLTree
	xmlTree;

	Attr
	attr;

	attr[ "read-only" ] = "yes";
	attr[ "date" ] = "2018-05-01";

	xmlTree.addTag( "config", attr ),
		xmlTree.addTag( "storages" ),
			xmlTree.addTag( "files" );
				xmlTree.addTag( "file" );
					xmlTree.addLeave( "name", "flash" );
					xmlTree.addLeave( "path", "~/flash/flashplayer_sa_29.exe" );
				xmlTree.up( );
				xmlTree.addTag( "file" );
					xmlTree.addLeave( "name", "fract" );
					xmlTree.addLeave( "path", "~/fract/FrACT3.10.0d.swf" );
				xmlTree.up( );
			xmlTree.up( );
			xmlTree.addTag( "directories" );
				xmlTree.addTag( "directory" );
					xmlTree.addLeave( "name", "data" );
					xmlTree.addLeave( "path", "~/data");
				xmlTree.up( );
			xmlTree.up( );
		xmlTree.up( );
		xmlTree.addTag( "examinations" );
			xmlTree.addTag( "definition" );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OD" );
					xmlTree.addLeave( "id", "1" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OS" );
					xmlTree.addLeave( "id", "2" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OD TF" );
					xmlTree.addLeave( "id", "3" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OS TF" );
					xmlTree.addLeave( "id", "4" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OD A" );
					xmlTree.addLeave( "id", "5" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OS A" );
					xmlTree.addLeave( "id", "6" );
					xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OD A cond" );
					xmlTree.addLeave( "id", "7" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addLeave( "alias", "OS A cond" );
					xmlTree.addLeave( "id", "8" );
				xmlTree.up( );
			xmlTree.up( );
			xmlTree.addTag( "collection" );
				xmlTree.addTag( "program" );
					xmlTree.addLeave( "name", "full" );
					xmlTree.addLeave( "measurement-1", "1" );
					xmlTree.addLeave( "measurement-2", "2" );
					xmlTree.addLeave( "measurement-3", "3" );
					xmlTree.addLeave( "measurement-4", "4" );
					xmlTree.addLeave( "measurement-5", "5" );
					xmlTree.addLeave( "measurement-6", "6" );
				xmlTree.up( );
				xmlTree.addTag( "program" );
					xmlTree.addLeave( "name", "full conditioned" );
					xmlTree.addLeave( "measurement-1", "1" );
					xmlTree.addLeave( "measurement-2", "2" );
					xmlTree.addLeave( "measurement-3", "3" );
					xmlTree.addLeave( "measurement-4", "4" );
					xmlTree.addLeave( "measurement-5", "7" );
					xmlTree.addLeave( "measurement-6", "8" );
				xmlTree.up( );
			xmlTree.up( );
		xmlTree.up( );
		xmlTree.addTag( "examinators" );
			xmlTree.addTag( "exminator" );
				xmlTree.addLeave( "id", "0111" );
				xmlTree.addLeave( "name", "Susi Sorglos" );
				xmlTree.addLeave( "sex", "female" );
				xmlTree.addLeave( "prefered-program", "full" );
			xmlTree.up( );
			xmlTree.addTag( "exminator" );
				xmlTree.addLeave( "id", "0113" );
				xmlTree.addLeave( "name", "Mandy Vogel" );
				xmlTree.addLeave( "sex", "female" );
				xmlTree.addLeave( "prefered-program", "full" );
			xmlTree.up( );

	xmlTree.save( "test.xml" );

	std::cout << xmlTree.toStr( ).toStdString( ) << std::endl;

	xmlTree.clear( );

	xmlTree.load( "test.xml" );

//	return app.exec( );
}
