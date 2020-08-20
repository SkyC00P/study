import dbsync.tools as tools
import unittest   # The test framework


class Test_TestIncrementDecrement(unittest.TestCase):
    def test_increment(self):
        self.assertEqual(tools.add(3), 4)
