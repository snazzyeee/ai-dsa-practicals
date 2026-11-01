"""Run from the project folder with python -m unittest tests.test_dsa_exam."""
import pathlib
import subprocess
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]


class ExamPracticals(unittest.TestCase):
    def test_programs(self):
        cases = {
            3: ("1\n1\n7 Amit 123\n1\n14 Riya 456\n2\n14\n4\n", ["Riya 456"]),
            4: ("1\n1\n1\n1 A\n1\n1\n3\n2 B\n1\n1\n2\n3 C\n3\n1\n2\n1\n3\n3\n1\n5\n", ["3: C", "Total members: 2"]),
            5: ("2\n1 2\n2\n1 2\n3\n1 2\n4\n", ["Seat booked.", "Seat already booked.", "Booking cancelled."]),
            6: ("2^3^2\n", ["Postfix: 232^^", "Result: 512"]),
            7: ("2\n1\n11\n1\n12\n1\n13\n2\n1\n13\n3\n4\n", ["Queue is full.", "Serving order 11.", "12 13"]),
            8: ("1\n5\n1\n3\n1\n7\n2\n3\n5\n7\n4\n4\n6\n", ["Nodes on longest path: 2", "Minimum: 3", "Found."]),
            9: ("2\nPune\nMumbai\n3\n1\n1 2 5\n2\n3\n4\n", ["Not connected.", "Pune: Mumbai(5)", "Connected."]),
        }
        with tempfile.TemporaryDirectory() as folder:
            for number, (inputs, expected) in cases.items():
                with self.subTest(practical=number):
                    executable = pathlib.Path(folder) / f"practical{number}.exe"
                    subprocess.run(["gcc", str(ROOT / "DSA" / f"practical{number}.c"), "-o", str(executable)], check=True)
                    result = subprocess.run([str(executable)], input=inputs, text=True, capture_output=True, timeout=5, check=True)
                    for text in expected:
                        self.assertIn(text, result.stdout)


if __name__ == "__main__":
    unittest.main()
