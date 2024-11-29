#include <gtest/gtest.h>

#include "executor.h"

using namespace car;

TEST(ExecutorTest, default_use_M_to_x0_y1_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	PoseHandler target(0, 1, 'N');
	std::string command = "M";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, default_use_MM_to_x0_y2_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	PoseHandler target(0, 2, 'N');
	std::string command = "MM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, default_use_L_to_x0_y0_W) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	PoseHandler target(0, 0, 'W');
	std::string command = "L";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, default_use_LM_to_xn1_y0_W) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	PoseHandler target(-1, 0, 'W');
	std::string command = "LM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, default_use_RM_to_x1_y0_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(ExecutorImpl::NewExecutor());
	PoseHandler target(1, 0, 'E');
	std::string command = "RM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x1_y1_E_use_FM_to_x3_y1_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'E'}));
	PoseHandler target(true, 3, 1, 'E');
	std::string command = "FM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x1_y1_N_use_FFM_to_x1_y2_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'N'}));
	PoseHandler target(false, 1, 2, 'N');
	std::string command = "FFM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x1_y1_E_use_FL_to_x2_y1_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'E'}));
	PoseHandler target(true, 2, 1, 'N');
	std::string command = "FL";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x1_y1_E_use_FR_to_x2_y1_S) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, 1, 1, 'E'}));
	PoseHandler target(true, 2, 1, 'S');
	std::string command = "FR";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_BM_to_xn1_y0_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(false, true, -1, 0, 'E');
	std::string command = "BM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_BL_to_x0_y0_S) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(false, true, 0, 0, 'S');
	std::string command = "BL";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_BR_to_x0_y0_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(false, true, -1, 0, 'N');
	std::string command = "BR";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_FM_to_x2_y0_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(false, false, 2, 0, 'E');
	std::string command = "FM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_FL_to_x1_y0_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(false, false, 1, 0, 'N');
	std::string command = "FL";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_FR_to_x1_y0_S) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(false, false, 1, 0, 'S');
	std::string command = "BR";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_BFM_to_xn2_y0_E) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(true, true, -2, 0, 'E');
	std::string command = "BFM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_BFL_to_xn1_y0_S) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(true, true, -1, 0, 'S');
	std::string command = "BFL";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_E_use_BFR_to_xn1_y0_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'E'}));
	PoseHandler target(true, true, -1, 0, 'N');
	std::string command = "BFR";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_N_use_BBM_to_x0_y1_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'N'}));
	PoseHandler target(false, false, 0, 1, 'N');
	std::string command = "BFM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}

TEST(ExecutorTest, x0_y0_N_use_FFM_to_x0_y1_N) {
	std::unique_ptr<ExecutorImpl> pExecutor(
		ExecutorImpl::NewExecutor({false, false, 0, 0, 'N'}));
	PoseHandler target(false, false, 0, 1, 'N');
	std::string command = "BFM";

	pExecutor->Execute(command);
	ASSERT_EQ(pExecutor->Query(), target);
}