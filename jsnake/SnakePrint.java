package test;

import java.util.Arrays;

public class SnakePrint {

	int[][] generateInputArray(int dimension) {

		int[][] input = new int[dimension][dimension];

		for (int i = 0; i < dimension; i++) {
			int start = i * dimension;

			for (int j = 0; j < dimension; j++) {
				input[i][j] = start + j;
				System.out.printf("%5d", input[i][j]);
			}
			System.out.println();
		}

		System.out.println("\n\n");

		return input;
	}

	void snakePrint(int[][] input) {

		// two terminating conditions
		if (input.length == 1) {
			System.out.println(input[0][0]);
			return;
		}

		if (input.length == 2) {
			System.out.printf("%5d\n", input[0][0]);
			System.out.printf("%5d\n", input[0][1]);
			System.out.printf("%5d\n", input[1][0]);
			System.out.printf("%5d\n", input[1][1]);
			return;
		}

		// this is the top row from left to right
		for (int i = 0; i < input.length - 1; ++i) {
			System.out.printf("%5d", input[0][i]);
		}
		System.out.println();

		// this is the right most column from top to bottom
		for (int i = 0; i < input.length - 1; ++i) {
			System.out.printf("%5d", input[i][input.length - 1]);
		}
		System.out.println();

		// this is the bottom row from right to left
		for (int i = input.length - 1; i > 0; --i) {
			System.out.printf("%5d", input[input.length - 1][i]);
		}
		System.out.println();

		// this is the first column from bottom to top
		for (int i = input.length - 1; i > 0; --i) {
			System.out.printf("%5d", input[i][0]);
		}
		System.out.println();

		int[][] newInput = new int[input.length - 2][input.length - 2];
		for (int i = 0, j = 1; j < input.length - 1; ++j, ++i) {
			newInput[i] = Arrays.copyOfRange(input[j], 1, input.length - 1);
		}

		// we've done with the input, set it to null for GC to consider
		input = null;
		snakePrint(newInput);

	}

	public static void main(String[] args) {

		SnakePrint snakeprint = new SnakePrint();
		int[][] input = snakeprint.generateInputArray(10);
		snakeprint.snakePrint(input);

	}

}
