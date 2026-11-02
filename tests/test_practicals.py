"""Run with: python -m unittest discover -s tests"""

import pathlib
import subprocess
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]


class PracticalChecks(unittest.TestCase):
    def test_flight_graph(self):
        with tempfile.TemporaryDirectory() as folder:
            executable = pathlib.Path(folder) / "graph"
            subprocess.run(["gcc", str(ROOT / "DSA" / "practical9.c"), "-o", str(executable)], check=True)
            result = subprocess.run([str(executable)], input="2\nPune\nMumbai\n3\n1\n1 2 5\n3\n4\n", text=True, capture_output=True, check=True)
            self.assertIn("Not connected.", result.stdout)
            self.assertIn("Connected.", result.stdout)


if __name__ == "__main__":
    unittest.main()
