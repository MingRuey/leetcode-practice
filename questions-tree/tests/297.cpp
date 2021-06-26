TEST(Serialize, sample) {
    // * Input: root = [1,2,3,null,null,4,5]
    // * Output: [1,2,3,null,null,4,5]

    TreeNode root = TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    (root.right)->left = new TreeNode(4);
    (root.right)->right = new TreeNode(5);

    Codec cdc;
    string result = cdc.serialize(&root);
    printf("%s\n", result.c_str());
}
