package MyLagrangeJava;

public class Lagrange { 

	public static double lagrange(int k, double arg, double[] x, double[] y) { 
		double result = 0.0; 
		for (int i = 0; i < k; i++) { 
			double F = 1.0; 
			for (int j = 0; j < k; j++) 
			if (j != i) 
			F *= (arg - x[j]) / (x[i] - x[j]); 
			result += F * y[i]; 
		} 
		return result; 
	} 
	
	public static void main(String[] args) { 
		double[] x = new double[] { -1.5, -0.75, 0.0, 0.75, 1.5 }; 
		double[] y = new double[] { -14.1014, -0.931596, 0.0, 0.931596, 14.1014 }; 
		double arg = 1.5; 
		System.out.println(lagrange(5, arg, x, y)); 
		System.out.println(Math.tan(arg)); 
	} 

}