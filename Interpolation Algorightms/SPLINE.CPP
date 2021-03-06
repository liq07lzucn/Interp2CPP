void spline(double x[], double y[], int n, double yp1,double ypn, double y2[])
{
    double u[100],aaa,sig,p,bbb,ccc,qn,un;
	int i,k;
    if( yp1 > 9.9e+29 )
	{
        y2[1] = 0;
        u[1] = 0;
	}
    else
	{
        y2[1] = -0.5;
        aaa = (y[2] - y[1]) / (x[2] - x[1]);
        u[1] = (3.0 / (x[2] - x[1])) * (aaa - yp1);
    }
    for (i = 2; i<=n-1; i++)
	{
        sig = (x[i] - x[i - 1]) / (x[i + 1] - x[i - 1]);
        p = sig * y2[i - 1] + 2.0;
        y2[i] = (sig - 1.0) / p;
        aaa = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
        bbb = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
        ccc = x[i + 1] - x[i - 1];
        u[i] = (6.0 * (aaa - bbb) / ccc - sig * u[i - 1]) / p;
    }
    if (ypn > 9.9e+29 )
	{
        qn = 0.0;
        un = 0.0;
	}
    else
	{
        qn = 0.5;
        aaa = ypn - (y[n] - y[n - 1]) / (x[n] - x[n - 1]);
        un = (3.0/ (x[n] - x[n - 1])) * aaa;
    }
    y2[n] = (un - qn * u[n - 1]) / (qn * y2[n - 1] + 1.0);
    for (k = n - 1;k>=1;k--)
        y2[k] = y2[k] * y2[k + 1] + u[k];
}
