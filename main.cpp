#include <iostream>
#include <QCoreApplication>
#include "xmltree.hpp"

int
main( int p_argc, char * p_argv[ ] ) {

//	QCoreApplication
//	app( p_argc, p_argv );

	XMLTree
	xmlTree;

	xmlTree.setDTD( "XML" );
	xmlTree.
		tag( "config" ).
		att( "date", "2018-05-07" ).
			tag( "storages" ).
				tag( "files" ).
					tag( "file" ).
						tag( "name" ).txt( "flash" ).gat( ).
						tag( "path" ).txt( "~/flash/flashplayer_sa_29.exe" ).gat( 2 ).
					tag( "file" ).
						tag( "name" ).txt( "fract" ).gat( ).
						tag( "path" ).txt( "~/fract/FrACT3.10.0d.swf" ).gat( 3 ).
				tag( "directories" ).
					tag( "directory" ).
						tag( "name" ).txt( "data" ).gat( ).
						tag( "path" ).txt( "~/data" ).gat( 4 ).
			tag( "examinations" ).
				tag( "definition" ).
					tag( "measurement" ).
						tag( "alias" ).txt( "OD" ).gat( ).
						tag( "id" ).txt( "1" ).gat( 2 ).
					tag( "measurement" ).
						tag( "alias" ).txt( "OS" ).gat( ).
						tag( "id" ).txt( "2" ).gat( 2 ).
					tag( "measurement" ).
						tag( "alias" ).txt( "ODTF" ).gat( ).
						tag( "id" ).txt( "3" ).gat( 2 ).
					tag( "measurement" ).
						tag( "alias" ).txt( "OSTF" ).gat( ).
						tag( "id" ).txt( "4" ).gat( 2 ).
					tag( "measurement" ).
						tag( "alias" ).txt( "ODA" ).gat( ).
						tag( "id" ).txt( "5" );/*
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addTagWithText( "alias", "OSA" );
					xmlTree.addTagWithText( "id", "6" );
					xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addTagWithText( "alias", "ODAC" );
					xmlTree.addTagWithText( "id", "7" );
				xmlTree.up( );
				xmlTree.addTag( "measurement" );
					xmlTree.addTagWithText( "alias", "OSAC" );
					xmlTree.addTagWithText( "id", "8" );
				xmlTree.up( );
			xmlTree.up( );
			xmlTree.addTag( "collection" );
				xmlTree.addTag( "program" );
					xmlTree.addTagWithText( "name", "full" );
					xmlTree.addTagWithText( "measurement-1", "1" );
					xmlTree.addTagWithText( "measurement-2", "2" );
					xmlTree.addTagWithText( "measurement-3", "3" );
					xmlTree.addTagWithText( "measurement-4", "4" );
					xmlTree.addTagWithText( "measurement-5", "5" );
					xmlTree.addTagWithText( "measurement-6", "6" );
				xmlTree.up( );
				xmlTree.addTag( "program" );
					xmlTree.addTagWithText( "name", "full conditioned" );
					xmlTree.addTagWithText( "measurement-1", "1" );
					xmlTree.addTagWithText( "measurement-2", "2" );
					xmlTree.addTagWithText( "measurement-3", "3" );
					xmlTree.addTagWithText( "measurement-4", "4" );
					xmlTree.addTagWithText( "measurement-5", "7" );
					xmlTree.addTagWithText( "measurement-6", "8" );
				xmlTree.up( );
			xmlTree.up( );
		xmlTree.up( );
		xmlTree.addTag( "examinators" );
			xmlTree.addTag( "exminator" );
				xmlTree.addTagWithText( "id", "0111" );
				xmlTree.addTagWithText( "name", "Susi Sorglos" );
				xmlTree.addTagWithText( "sex", "female" );
				xmlTree.addTagWithText( "preferred-program", "full" );
			xmlTree.up( );
			xmlTree.addTag( "exminator" );
				xmlTree.addTagWithText( "id", "0113" );
				xmlTree.addTagWithText( "name", "Hans Wurst" );
				xmlTree.addTagWithText( "sex", "male" );
				xmlTree.addTagWithText( "preferred-program", "full conditioned" );
*/

	xmlTree.save( "test.xml" );

	xmlTree.load( "test.xml" );

	xmlTree.save( "test2.xml" );

//	std::cout << xmlTree.toStr( ).toStdString( ) << std::endl;

/*
	xmlTree.setDTD( "<!DOCTYPE test>" );
	xmlTree.addTag( "list-characters" );
		xmlTree.addTag( "list-numbers" );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "zero" );
				xmlTree.addTagWithText( "val-symbol", "0" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "one" );
				xmlTree.addTagWithText( "val-symbol", "1" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "two" );
				xmlTree.addTagWithText( "val-symbol", "2" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "three" );
				xmlTree.addTagWithText( "val-symbol", "3" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "four" );
				xmlTree.addTagWithText( "val-symbol", "4" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "five" );
				xmlTree.addTagWithText( "val-symbol", "5" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "six" );
				xmlTree.addTagWithText( "val-symbol", "6" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "seven" );
				xmlTree.addTagWithText( "val-symbol", "7" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "eight" );
				xmlTree.addTagWithText( "val-symbol", "8" );
				xmlTree.up( );
			xmlTree.addTag( "obj-number" );
				xmlTree.addTagWithText( "val-name", "nine" );
				xmlTree.addTagWithText( "val-symbol", "9" );
				xmlTree.up( );
			xmlTree.up( );
		xmlTree.addTag( "list-letters" );
			xmlTree.addTag( "list-small" );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "a" );
					xmlTree.addTagWithText( "val-symbol", "a" );
					xmlTree.up( );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "b" );
					xmlTree.addTagWithText( "val-symbol", "b" );
					xmlTree.up( );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "c" );
					xmlTree.addTagWithText( "val-symbol", "c" );
					xmlTree.up( );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "d" );
					xmlTree.addTagWithText( "val-symbol", "d" );
					xmlTree.up( );
				xmlTree.up( );
			xmlTree.addTag( "list-capital" );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "a" );
					xmlTree.addTagWithText( "val-symbol", "A" );
					xmlTree.up( );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "b" );
					xmlTree.addTagWithText( "val-symbol", "B" );
					xmlTree.up( );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "c" );
					xmlTree.addTagWithText( "val-symbol", "C" );
					xmlTree.up( );
				xmlTree.addTag( "obj-letter" );
					xmlTree.addTagWithText( "val-name", "d" );
					xmlTree.addTagWithText( "val-symbol", "D" );

*/
/*
	xmlTree.setDTD( "<!DOCTYPE test>" );
	xmlTree.addTag( "list-characters" );
		xmlTree.addTag( "list-numbers" );
			xmlTree.addTagWithText( "id-0", "0" );
			xmlTree.addTagWithText( "id-1", "1" );
			xmlTree.addTagWithText( "id-2", "2" );
			xmlTree.addTagWithText( "id-3", "3" );
			xmlTree.addTagWithText( "id-4", "4" );
			xmlTree.addTagWithText( "id-5", "5" );
			xmlTree.addTagWithText( "id-6", "6" );
			xmlTree.addTagWithText( "id-7", "7" );
			xmlTree.addTagWithText( "id-8", "8" );
			xmlTree.addTagWithText( "id-9", "9" );
			xmlTree.up( );
		xmlTree.addTag( "list-letters" );
			xmlTree.addTag( "list-small" );
				xmlTree.addTagWithText( "id-0", "a" );
				xmlTree.addTagWithText( "id-1", "b" );
				xmlTree.addTagWithText( "id-2", "c" );
				xmlTree.addTagWithText( "id-3", "d" );
				xmlTree.up( );
			xmlTree.addTag( "list-capital" );
				xmlTree.addTagWithText( "id-0", "A" );
				xmlTree.addTagWithText( "id-1", "B" );
				xmlTree.addTagWithText( "id-2", "C" );
				xmlTree.addTagWithText( "id-3", "D" );



	//xmlTree.clear( );
	xmlTree.save( "test.xml" );

	xmlTree.load( "test.xml" );

	xmlTree.save( "test2.xml" );

*/
	XMLTree
	subdivision;

	subdivision.load( "subdivision.xml" );
	subdivision.save( "subdivision-copy.xml" );

	xmlTree.addTag( "Hello" );
	xmlTree.setText( "Hallo" );

	Attrs
	attrs;

	attrs << Attr( "date", "2018-05-07" );

	xmlTree.setAttr( attrs );

	xmlTree.setNSpace( NSpaces( ) << NSpace( "lpzg", "https://uni-leipzig.de" ) );

	xmlTree.addTag( "empty" );
	xmlTree.addTag( "emptyness" );
	xmlTree.up();
	xmlTree.addTag( "emptynessness" );
	xmlTree.save( "test3.xml" );

	XMLTree
	xmlTree2;

	xmlTree2.load( "test3.xml" );

	xmlTree2.save( "test4.xml" );

	XMLTree
	cfg;

	cfg.load( "cfg.xml" );

	cfg.rp( ).att( "date", "2018-05-07" );

	std::cout << cfg.rp( ).in( "config" ).in( "storages" ).in( "directories" ).in( "data" ).att( "type", "dir" ).curr( )->data( ).toStdString( ) << std::endl;
	std::cout << cfg.rp( ).in( "config" ).in( "storages" ).in( "files" ).in( "flash" ).att( "type", "exe" ).curr( )->data( ).toStdString( ) << std::endl;
	std::cout << cfg.rp( ).in( "config" ).in( "storages" ).in( "files" ).in( "fract" ).att( "type", "swf" ).curr( )->data( ).toStdString( ) << std::endl;
	std::cout << cfg.rp( ).in( "config" ).in( "storages" ).in( "files" ).tag( "config" ).txt( "cfg.xml" ).nspc( NSpaces() << NSpace( "local", "./" ) ).curr( )->data( ).toStdString( ) << std::endl;

	cfg.save( "cfg-copy.xml" );


	XMLTree
	longTree,
	midTree,
	shortTree;

	longTree.setDTD( "xml-animals-deutsch");
	longTree.rp( ).
		tag( "Lebewesen" ).
			nspc( NSpaces( ) << NSpace( "anim", "animals" ) ).
			tag( "Pilze" ).
				tag( "Giftpilze" ).
					tag( "Fliegenpilz" ).up( ).
					tag( "Knollenblätterpliz" ).up( ).
					tag( "Pantherpilz" ).up( 2 ).
				tag( "Speisepilze" ).
					tag( "Marone" ).up( ).
					tag( "Pfifferling" ).up( ).
					tag( "Steinpliz" ).up( 3 ).
			tag( "Pflanzen" ).
				tag( "Bäume" ).
					tag( "Tanne" ).att( "Laub", "immergrün" ).up( ).
					tag( "Linde" ).att( "Laub", "sommergrün" ).up( ).
					tag( "Eiche" ).att( "Laub", "sommergrün" ).up( 2 ).
				tag( "Gräser" ).
					tag( "Gras" ).up( ).
					tag( "Bambus" ).up( 2 ).
				tag( "Mose" ).
					tag( "Waldmos" ).up( 3 ).
			tag( "Tiere" ).
				tag( "Fisch" ).
					tag( "Guppie" ).up( ).
					tag( "Hai" ).up( ).
					tag( "Forelle" ).up( 2 ).
				tag( "Vogel" ).
					tag( "Strauß" ).up( ).
					tag( "Sperling" ).up( ).
					tag( "Möve" ).up( 2 ).
				tag( "Säugetier" ).
					tag( "Igel" ).up( ).
					tag( "Pferd" ).up( ).
					tag( "Hund" ).up( 2 ).
				tag( "Echse" ).
					tag( "Blindschleiche" ).up( ).
					tag( "Zauneidechse" );


	longTree.save( "longTree.xml" );


	XMLTree
	myCfg;

	myCfg
	.addTag( "cfg" )
		.addTag( "files-and-dirs" )
			.addTag( "flash" ).att( "path", "./" ).att( "filename", "flashplayer_sa_29.exe" ).att( "ending", "exe" ).att( "type", "file" ).up( )
			.addTag( "fract" ).att( "path", "./" ).att( "filename", "FrACT3.10.0d.swf" ).att( "ending", "swf" ).att( "type", "file" ).up( )
			.addTag( "data" ).att( "path", "./" ).att( "filename", "data" ).att( "ending", "" ).att( "type", "directory" ).up( 2 )
		.addTag( "examinators" )
			.addTag( "MB" ).att( "id", "111" ).att( "vname", "Simone" ).att( "nname", "Bock" ).up( )
			.addTag( "GH" ).att( "id", "7411" ).att( "vname", "Gudrun" ).att( "nname", "Hilm" ).up( )
			.addTag( "FB" ).att( "id", "8111" ).att( "vname", "Frank" ).att( "nname", "Bär" ).up( );

	myCfg.save( "mycfg.xml" );


	XMLTree
	data;

	data
		.addTag( "SESSION" ).att( "date", "2018-05-08" ).nspc( NSpaces( ) << NSpace( "lpzg", "https://www.uni-leipzig.de" ) )
			.addTag( "UID" ).att( "uid", "8111" )
				.addTag( "MEASUREMENTS" ).att( "type", "visus" ).att( "time", "11:33" ).att( "oculus", "dexter" ).att( "trial-frame", "no" ).att( "aperture", "no" )
						.addTag( "M1" ).att( "angle-given", "30" ).att( "angle-response", "45" ).att( "VA", "-2.1" ).att( "logMar", "-.1" ).up( )
						.addTag( "M2" ).att( "angle-given", "45" ).att( "angle-response", "225" ).att( "VA", "-1.1" ).att( "logMar", "+.1" ).up( )
						.addTag( "M3" ).att( "angle-given", "90" ).att( "angle-response", "135" ).att( "VA", "-3.1" ).att( "logMar", "-.6" ).up( );

	data.save( "data.xml" );

	data.clear( );

	data.load( "data.xml" );

	double
	m3LogMar[ 3 ];

	for( int i = 0; i < 3; ++ i ) {

		m3LogMar[ i ] = data.rp( ).in( "SESSION" ).in( "UID" ).in( "MEASUREMENTS" ).in( QString( "M%1" ).arg( i ) ).curr( )->attrs( ).value( "logMar" ).toDouble( );
	}

	std::cout << std::endl;
	std::cout << "m3LogMar[ 0 ]: "<< m3LogMar[ 0 ] << std::endl;
	std::cout << "m3LogMar[ 1 ]: "<< m3LogMar[ 1 ] << std::endl;
	std::cout << "m3LogMar[ 2 ]: "<< m3LogMar[ 2 ] << std::endl;


	subdivision.clear( );

	subdivision.load( "subdivision.xml" );

	std::cout << "diameter: " <<
	subdivision.rp( )
		.in( "LandXML" )
			.in( "PipeNetworks" )
				.in( "PipeNetwork" ).
					 in( "Structs" )
						.in( "Struct", 3 )
							.in( "Invert", 1 ).curr( )->attrs( ).value("elev" ).toDouble( ) << std::endl;


//	return app.exec( );
}
