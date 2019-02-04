// Bring in my package's API, which is what I'm testing
//include "niels_state_machine/niels_state_machine_node.cpp"
// Bring in gtest
#include <gtest/gtest.h>

// Declare a test
TEST(TestSuite, testCase1)
{
	EXPECT_TRUE(meval::ContainsOperators("+"));
      	EXPECT_TRUE(meval::ContainsOperators("-"));
  	EXPECT_TRUE(meval::ContainsOperators("/"));
    	EXPECT_TRUE(meval::ContainsOperators("*"));
}

// Declare another test
TEST(TestSuite, testCase2)
{
	EXPECT_EQ(5, meval::EvaluateMathExpression("2+3"));
	EXPECT_EQ(5, meval::EvaluateMathExpression("2 + 3"));
	EXPECT_EQ(10, meval::EvaluateMathExpression("20/2"));
	EXPECT_EQ(-4, meval::EvaluateMathExpression("6 - 10"));
	EXPECT_EQ(24, meval::EvaluateMathExpression("6 * 4"));
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  ros::NodeHandle nh;
  return RUN_ALL_TESTS();
}
