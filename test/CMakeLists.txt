enable_testing()

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include")

ADD_EXECUTABLE(runBinTreeUnitTests Test_BinTree.cpp main.cpp)

TARGET_LINK_LIBRARIES(runBinTreeUnitTests
    bin_tree
    libgtest
    libgmock
)

add_test(BinTreeUnitTests runBinTreeUnitTests)
