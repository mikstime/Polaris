#include "gtest/gtest.h"
#include "isometry.h"

using namespace Polaris;

class TestClassXYZ
{
public:
	double x, y, z;

	TestClassXYZ( double _x, double _y, double _z ) : x( _x ), y( _y ), z( _z ) {};
};

class TestClassXY
{
public:
	int x, y;

	TestClassXY( double _x, double _y ) : x( _x ), y( _y ) {};
};

TEST( TestIsometry, TestAngle )
{
	double angle = 90;
	double scale = 1;

	Isometry< TestClassXYZ, TestClassXY > isometry( angle, scale );


	std::vector< TestClassXYZ > V3;
	for ( int i = 0; i < 10; i++ )
	{
		TestClassXYZ tmp( 1, 1, 1 );
		V3.push_back( tmp );
	}

	std::vector< TestClassXY > V2;

	std::vector< TestClassXY > Ans;
	for ( int i = 0; i < 10; i++ )
	{
		TestClassXY tmp( 1, -1 );
		V2.push_back( tmp );
	}

	isometry.TransformCoordinates( V3, V2 );
	EXPECT_EQ( Ans, V2 );
	EXPECT_TRUE( true );
}

TEST( TestIsometry, TestScale )
{
	double angle = 0;
	double scale = 2;

	Isometry< TestClassXYZ, TestClassXY > isometry( angle, scale );


	std::vector< TestClassXYZ > V3;
	for ( int i = 0; i < 10; i++ )
	{
		TestClassXYZ tmp( 1, 1, 1 );
		V3.push_back( tmp );
	}

	std::vector< TestClassXY > V2;

	std::vector< TestClassXY > Ans;
	for ( int i = 0; i < 10; i++ )
	{
		TestClassXY tmp( 2, 2 );
		V2.push_back( tmp );
	}

	isometry.TransformCoordinates( V3, V2 );
	EXPECT_EQ( Ans, V2 );
	EXPECT_TRUE( true );
}

TEST( TestIsometry, TestZeroCoordinates )
{
	double angle = 10;
	double scale = 3;

	Isometry< TestClassXYZ, TestClassXY > isometry( angle, scale );


	std::vector< TestClassXYZ > V3;
	for ( int i = 0; i < 10; i++ )
	{
		TestClassXYZ tmp( 0, 0, 0 );
		V3.push_back( tmp );
	}

	std::vector< TestClassXY > V2;

	std::vector< TestClassXY > Ans;
	for ( int i = 0; i < 10; i++ )
	{
		TestClassXY tmp( 0, 0 );
		V2.push_back( tmp );
	}

	isometry.TransformCoordinates( V3, V2 );
	EXPECT_EQ( Ans, V2 );
	EXPECT_TRUE( true );
}

TEST( TestIsometry, TestNegativeScale )
{
	double angle = 0;
	double scale1 = 2;

	Isometry< TestClassXYZ, TestClassXY > isometry( angle, scale1 );

	double scale2 = -2;

	try
	{
		isometry.Scaling( scale2 );
	}
	catch ( NegativeScaleException error )
	{
		EXPECT_EQ(error.what(), std::string( "Scale is Negativ" ) );
		EXPECT_TRUE( true );
	}
	EXPECT_FALSE( false );
}

int main( int argc, char * argv[] )
{
	testing::InitGoogleTest( & argc, argv );
	return RUN_ALL_TESTS();
}