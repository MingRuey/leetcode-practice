TEST(CountSmaller, sample) {
    vector<int> input {5, 2, 6, 1};
    vector<int> expected {2, 1, 1, 0};

    Solution s;
    auto result = s.countSmaller(input);
    EXPECT_THAT(result, testing::ContainerEq(expected));
}
