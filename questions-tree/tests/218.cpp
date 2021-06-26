TEST(Skyline, sample) {
    vector<vector<int>> input = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> expected = {{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}};

    Solution s;
    auto result = s.getSkyline(input);
    EXPECT_THAT(result, testing::ContainerEq(expected));
}

TEST(Skyline, same_height) {
    vector<vector<int>> input = {{0,2,3},{2,5,3}};
    vector<vector<int>> expected = {{0,3},{5,0}};

    Solution s;
    auto result = s.getSkyline(input);
    EXPECT_THAT(result, testing::ContainerEq(expected));
}

TEST(Skyline, same_x) {
    vector<vector<int>> input = {{1,2,1},{1,2,2},{1,2,3}};
    vector<vector<int>> expected = {{1,3},{2,0}};

    Solution s;
    auto result = s.getSkyline(input);
    EXPECT_THAT(result, testing::ContainerEq(expected));
}
