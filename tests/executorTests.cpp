#include <gtest/gtest.h>

#include "executor.h"

using namespace car;

TEST(ExecutorTest, default_use_M_to_x0_y1_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	std::string command = "M";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 0);
	ASSERT_EQ(pExecutor->Query().y, 1);
	ASSERT_EQ(pExecutor->Query().heading, 'N');
}

TEST(ExecutorTest, default_use_MM_to_x0_y2_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	std::string command = "MM";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 0);
	ASSERT_EQ(pExecutor->Query().y, 2);
	ASSERT_EQ(pExecutor->Query().heading, 'N');
}

TEST(ExecutorTest, default_use_L_to_x0_y0_W) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	std::string command = "L";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 0);
	ASSERT_EQ(pExecutor->Query().y, 0);
	ASSERT_EQ(pExecutor->Query().heading, 'W');
}

TEST(ExecutorTest, default_use_LM_to_xn1_y0_W) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	std::string command = "LM";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, -1);
	ASSERT_EQ(pExecutor->Query().y, 0);
	ASSERT_EQ(pExecutor->Query().heading, 'W');
}

TEST(ExecutorTest, default_use_RM_to_x1_y0_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	std::string command = "RM";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 1);
	ASSERT_EQ(pExecutor->Query().y, 0);
	ASSERT_EQ(pExecutor->Query().heading, 'E');
}

TEST(ExecutorTest, x1_y1_E_use_FM_to_x3_y1_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'E'}));
	std::string command = "FM";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 3);
	ASSERT_EQ(pExecutor->Query().y, 1);
	ASSERT_EQ(pExecutor->Query().heading, 'E');
}

TEST(ExecutorTest, x1_y1_N_use_FFM_to_x1_y2_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'N'}));
	std::string command = "FFM";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 1);
	ASSERT_EQ(pExecutor->Query().y, 2);
	ASSERT_EQ(pExecutor->Query().heading, 'N');
}

TEST(ExecutorTest, x1_y1_E_use_FL_to_x2_y1_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'E'}));
	std::string command = "FL";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 2);
	ASSERT_EQ(pExecutor->Query().y, 1);
	ASSERT_EQ(pExecutor->Query().heading, 'N');
}

TEST(ExecutorTest, x1_y1_E_use_FR_to_x2_y1_S) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'E'}));
	std::string command = "FR";
	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query().x, 2);
	ASSERT_EQ(pExecutor->Query().y, 1);
	ASSERT_EQ(pExecutor->Query().heading, 'S');
}