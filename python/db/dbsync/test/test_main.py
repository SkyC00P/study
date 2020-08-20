import dbsync.tools as tools
import unittest   # The test framework


class Test_TestIncrementDecrement(unittest.TestCase):
    def test_increment(self):
        self.assertIsNotNone(tools.OracleDB(None))
