"""Run with: python -m unittest discover -s tests"""

import importlib.util
import pathlib
import subprocess
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]


def load(name):
    spec = importlib.util.spec_from_file_location(name, ROOT / "AI" / (name + ".py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


class PracticalChecks(unittest.TestCase):
    def test_expert_rules(self):
        expert = load("practical_1_expert_system")
        self.assertEqual(expert.diagnose({"fever", "cough"}, expert.RULES), ["flu"])
        self.assertEqual(expert.diagnose({"fever"}, expert.RULES), [])

    def test_maze_searches(self):
        search = load("practical_2_bfs_dfs")
        astar = load("practical_3_a_star")
        maze = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
        start, goal = (0, 0), (2, 2)
        bfs_path, _ = search.bfs(maze, start, goal)
        dfs_path, _ = search.dfs(maze, start, goal)
        astar_path, _ = astar.a_star(maze, start, goal)
        self.assertEqual(len(bfs_path), 5)
        self.assertEqual(len(astar_path), len(bfs_path))
        self.assertEqual((dfs_path[0], dfs_path[-1]), (start, goal))
        blocked = [[0, 1, 0]]
        self.assertEqual(search.bfs(blocked, (0, 0), (0, 2))[0], [])
        self.assertEqual(astar.a_star(blocked, (0, 0), (0, 2))[0], [])

    def test_flight_graph(self):
        with tempfile.TemporaryDirectory() as folder:
            executable = pathlib.Path(folder) / "graph"
            subprocess.run(["gcc", str(ROOT / "DSA" / "practical9.c"), "-o", str(executable)], check=True)
            result = subprocess.run([str(executable)], input="2\nPune\nMumbai\n3\n1\n1 2 5\n3\n4\n", text=True, capture_output=True, check=True)
            self.assertIn("Not connected.", result.stdout)
            self.assertIn("Connected.", result.stdout)


if __name__ == "__main__":
    unittest.main()
