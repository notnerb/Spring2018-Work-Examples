import java.lang.Math.*;

import static java.lang.Double.*;


public class RayCasting {
    static boolean intersects(double[] A, double[] B, double[] P) {
        if (A[1] > B[1])
            return intersects(B, A, P);

        if (P[1] == A[1] || P[1] == B[1])
            P[1] += 0.0001;

        if (P[1] > B[1] || P[1] < A[1] || P[0] >= max(A[0], B[0]))
            return false;

        if (P[0] < min(A[0], B[0]))
            return true;

        double red = (P[1] - A[1]) / (double) (P[0] - A[0]);
        double blue = (B[1] - A[1]) / (double) (B[0] - A[0]);
        return red >= blue;
    }

    static boolean contains(double[][] shape, double[] pnt) {
        boolean inside = false;
        int len = shape.length;
        for (int i = 0; i < len; i++) {
            if (intersects(shape[i], shape[(i + 1) % len], pnt))
                inside = !inside;
        }
        return inside;
    }

    public static void main(String[] a) {
        double[][] testPoints = {{-80.5, 26.5}, {10, 16}, {-20, 10}, {0, 10},
                {20, 10}, {16, 10}, {20, 20}};

        for (double[][] shape : shapes) {
            for (double[] pnt : testPoints)
                System.out.printf("%7s ", contains(shape, pnt));
            System.out.println();
        }
    }

    final static double[][] square = {{-81, 25},{-81,27},{-79, 27},{-79,25}};

    final static double[][] hexagon = {{6, 0}, {14, 0}, {20, 10}, {14, 20},
            {6, 20}, {0, 10}};

    final static double[][][] shapes = {square, hexagon};
}
