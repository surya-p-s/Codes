import java.util.*;
public class HamiltonianCycles {
 private int V;
 private int[][] graph;
 private List<List<Integer>> allCycles;
 public HamiltonianCycles(int vertices) {
 V = vertices;
 graph = new int[V][V];
 allCycles = new ArrayList<>();
 }
 public void addEdge(int src, int dest) {
 graph[src][dest] = 1;
 graph[dest][src] = 1;
 }
 public List<List<Integer>> findHamiltonianCycles() {
 boolean[] visited = new boolean[V];
 List<Integer> path = new ArrayList<>();
 path.add(0);
 hamiltonianCyclesUtil(visited, path, 0, 0);
 return allCycles;
 }
 private void hamiltonianCyclesUtil(boolean[] visited, List<Integer>
path, int pos, int start) {
 if (path.size() == V) {
 if (graph[path.get(path.size() - 1)][path.get(0)] == 1) {
 List<Integer> cycle = new ArrayList<>(path);
 allCycles.add(cycle);
 }
 return;
 }
24
 visited[pos] = true;
 for (int v = 0; v < V; v++) {
 if (!visited[v] && graph[pos][v] == 1) {
 path.add(v);
 hamiltonianCyclesUtil(visited, path, v, start);
 path.remove(path.size() - 1);
 }
 }
 visited[pos] = false;
 }
 public static void main(String[] args) {
 int vertices = 5;
 HamiltonianCycles hc = new HamiltonianCycles(vertices);
 hc.addEdge(0, 1);
 hc.addEdge(0, 3);
 hc.addEdge(1, 2);
 hc.addEdge(1, 4);
 hc.addEdge(2, 3);
 hc.addEdge(2, 4);
 hc.addEdge(3, 4);
 List<List<Integer>> cycles = hc.findHamiltonianCycles();
 if (cycles.isEmpty()) {
 System.out.println("No Hamiltonian cycles found");
 } else {
 System.out.println("Hamiltonian Cycles:");
 for (List<Integer> cycle : cycles) {
 System.out.println(cycle);
 }
 }
 }}