#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(string(guessNumber));
            FAIL();
        }
        catch (exception e) {
            //PASS
        }
    }

};

TEST(BaseballGame, TryGameTest) {
    EXPECT_EQ(1, 1);
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvaildCase)
{
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber)
{
    //Baseball game("123");
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}

int main() {
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}