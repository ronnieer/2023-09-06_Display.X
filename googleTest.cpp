#include <gtest/gtest.h>

extern "C" {
#include "DiodTest.h"

}

class PhotodiodeLimitTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(PhotodiodeLimitTest, LimitADC_0){
    //ARRANGE
    float photoDiodeResult = 0;
    int timeENAMeasure;
    //ACT
    unitTest(photoDiodeResult);
    //ASSERT
    EXPECT_FLOAT_EQ(1, timeENAMeasure);
}

TEST_F(PhotodiodeLimitTest, LimitADC_255){
    //ARRANGE
    float photoDiodeResult = 255;
    int timeENAMeasure;
    //ACT
    unitTest(photoDiodeResult);
    //ASSERT
    EXPECT_FLOAT_EQ(110, timeENAMeasure);
}

TEST_F(PhotodiodeLimitTest, LimitADC_255_Fail){
    //ARRANGE
    float photoDiodeResult = 255;
    int timeENAMeasure;
    //ACT
    unitTest(photoDiodeResult);
    //ASSERT
    EXPECT_FLOAT_EQ(120, timeENAMeasure);
}

// TEST_F(FizzbuzzTest2, FractionByThreeAndFiveWithNoRest){
//     //ARRANGE
//     int tal = 15;
//     char buffer[10];
//     //ACT
//     calculateFizzBuzz2(tal, buffer);
//     //ASSERT
//     ASSERT_STREQ("FizzBuzz", buffer);
// }

// TEST_F(FizzbuzzTest2, FractionByThreeAndFiveWithRest){
//     //ARRANGE
//     int tal = 2;
//     char buffer[10];
//     //ACT
//     calculateFizzBuzz2(tal, buffer);
//     //ASSERT
//     ASSERT_STREQ("2", buffer);
// }



// // Funktionen behöver inte ha en return för att vara testbar?
// // TIPS: Dela upp er kod! Testbar funktion -> bara beräkningar, inga scanf/printf
// TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy3and5ThenFizzBuzzShouldBeReturned){
//     //ARRANGE
//     int tal = 30;
//     char buffer[10];
//     //ACT
//     calculateFizzBuzz(tal, buffer);
//     //ASSERT
//     ASSERT_STREQ("FizzBuzz", buffer);
// }

// //Om tal jämt delbart med 3 och 5 -> "fizzbuzz"
// //Om tal jämt delbart med 3 -> "fizz"
// TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy3ThenFizzShouldBeReturned){
//     //ARRANGE
//     int tal = 6;
//     char buffer[10];
//     //ACT
//     calculateFizzBuzz(tal, buffer);
//     //ASSERT
//     ASSERT_STREQ("Fizz", buffer);
// }

// //Om tal jämt delbart med 5 -> "buzz"
// TEST_F(FizzbuzzTest,WhenTalIsDivisibleBy10ThenBuzzShouldBeReturned){
//     //ARRANGE
//     int tal = 10;
//     char buffer[10];
//     //ACT
//     calculateFizzBuzz(tal, buffer);
//     //ASSERT
//     ASSERT_STREQ("Buzz", buffer);
// }


// // annars talet som sträng
// TEST_F(FizzbuzzTest,WhenTalIsNotDivisableBy3or5ThenNumberShouldBeReturned){
//     //ARRANGE
//     int tal = 8;
//     char buffer[10];
//     //ACT
//     calculateFizzBuzz(tal, buffer);
//     //ASSERT
//     ASSERT_STREQ("8", buffer);
// }