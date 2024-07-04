#include <iostream>
#include <cmath>
using namespace std;

struct dot{
    float x;
    float y;
    float z;

    dot(float x, float y, float z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
};


/*Calcular la distancia entre dos puntos en 2 dimensiones*/
float points_distance(float x1, float y1, float x2, float y2);
/*Calcular la distancia entre 2 puntos en 3 dimensiones*/
float points_distance(float x1, float y1, float z1, float x2, float y2, float z2);


/*Calcular el vector resultante de la suma de dos vectores en 2 dimensiones*/
dot vect_result(float x1, float y1, float x2, float y2);
/*Calcular el vector resultante de la suma de dos vectores en 3 dimensiones*/
dot vect_result(float x1, float y1, float z1, float x2, float y2, float z2);


/*Calcular el vector resultante de un arreglo de N vectores para 2 dimensiones*/
dot vect_resultN( dot vecList[], int sizeN);
/*Calcular el vector resultante de un arreglo de N vectores para 3 dimensiones*/
dot vect_resultN( dot vecList[], int sizeN, float x1);

/*Resultado del producto escalar 2 dimensiones*/
float escalar(float x1, float y1, float x2, float y2);
/*Resultado del producto escalar 3 dimensiones*/
float escalar(float x1, float y1, float z1, float x2, float y2, float z2);

/*Resultado del producto cruz 2 dimensiones*/
dot crossProduct(float x1, float y1, float x2, float y2);
/*Resultado del producto cruz 3 dimensiones*/
dot crossProduct(float x1, float y1, float z1, float x2, float y2, float z2);

/*Imprimir el vector siguiendo el formato -> u = i + j + k (vector unitario),
e indicar el plano donde se ubica*/
void vectFormatAndPlace(float x, float y, float z);

/*Realizar una función que me permita resolver un sistema de fuerzas*/
void forcesSystem(dot vectList[], int sizeN);


int main(){

    float x1, y1, z1, x2, y2, z2; 
    cout<<"Ingrese las coordenadas x1, y1, z1, del punto p1: "<<endl;
    cout<<"x1: ";
    cin>>x1;
    cout<<"y1: ";
    cin>>y1;
    cout<<"z1: ";
    cin>>z1;
    cout<<"Ahora ingrese las coordenadas x2, y2, z2, del punto p2: "<<endl;
    cout<<"x2: ";
    cin>>x2;
    cout<<"y2: ";
    cin>>y2;
    cout<<"z2: ";
    cin>>z2;
    
    cout<<endl;
    cout<<"Para el primer punto: ";
    vectFormatAndPlace(x1, y1, z1);
    cout<<"Para el segundo punto: ";
    vectFormatAndPlace(x2, y2, z2);
    
    cout<<endl;
    cout<<"La distancia entre los dos puntos (en 2 dimensiones) es: "<<points_distance(x1, y1, x2, y2)<<endl;
    cout<<"La distancia entre los dos puntos (en 3 dimensiones) es: "<<points_distance(x1, y1, z1, x2, y2, z2)<<endl;

    dot sum2D = vect_result(x1, y1, x2, y2);
    dot sum3D = vect_result(x1, y1, z1, x2, y2, z2);
    cout<<endl;
    cout<<"El vector resultante de la suma de los vectores (en 2 dimensiones) es: "<<"("<<sum2D.x<<", "<<sum2D.y<<", "<<sum2D.z<<")"<<endl;
    cout<<"El vector resultante de la suma de los vectores (en 3 dimensiones) es: "<<"("<<sum3D.x<<", "<<sum3D.y<<", "<<sum3D.z<<")"<<endl;
    
    cout<<endl;
    cout<<"El producto escalar de los dos vectores (en 2 dimensiones) es: "<<escalar(x1, y1, x2, y2)<<endl;
    cout<<"El producto escalar de los dos vectores (en 3 dimensiones) es: "<<escalar(x1, y1, z1, x2, y2, z2)<<endl;
 
    dot product2D = crossProduct(x1, y1, x2, y2);
    dot product3D = crossProduct(x1, y1, z1, x2, y2, z2);
    cout<<endl;
    cout<<"El producto cruz de los 2 vectores (en 2 dimensiones) es: "<<"("<<product2D.x<<", "<<product2D.y<<", "<<product2D.z<<")"<<endl;
    cout<<"El producto cruz de los 2 vectores (en 3 dimensiones) es: "<<"("<<product3D.x<<", "<<product3D.y<<", "<<product3D.z<<")"<<endl;


    dot vectList[] = {{4, 2, 9},{2.2, 35, -12},{0, 2.1, -1.2},{2, 3.4, -5},{1, -9, 8}};
    dot pointSum2D = vect_resultN(vectList, 5);
    dot pointSum3D = vect_resultN(vectList, 5, 0.0);
    cout<<endl;
    cout<<"Para los vectores (4, 2, 9), (2.2, 35, -12), (0, 2.1, -1.2), (2, 3.4, -5) y (1, -9, 8): "<<endl;
    cout<<"El vector resultante de su suma en 2 dimensiones es: "<<"("<<pointSum2D.x<<", "<<pointSum2D.y<<", "<<pointSum2D.z<<")"<<endl;
    cout<<"El vector resultante de su suma en 3 dimensiones es: "<<"("<<pointSum3D.x<<", "<<pointSum3D.y<<", "<<pointSum3D.z<<")"<<endl;

    cout<<endl;
    cout<<"Para los vectores de fuerza (4, 2, 9), (2.2, 35, -12), (0, 2.1, -1.2), (2, 3.4, -5) y (1, -9, 8): "<<endl;
    forcesSystem(vectList, 5);
}



float points_distance(float x1, float y1, float x2, float y2){

    float distance;
    distance = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
   
    return distance; 
}

float points_distance(float x1, float y1, float z1, float x2, float y2, float z2){

    float distance;
    distance = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2) + pow((z2-z1), 2));
   
    return distance; 
}

dot vect_result(float x1, float y1, float x2, float y2){
    dot vectorSum = {x1+x2, y1+y2, 0};
    return vectorSum;
}

dot vect_result(float x1, float y1, float z1, float x2, float y2, float z2){
    dot vectorSum = {x1+x2, y1+y2, z1+z2};
    return vectorSum;
}

dot vect_resultN( dot vecList[], int sizeN){
    float xr = 0.0;
    float yr = 0.0;

    for(int i = 0; i<sizeN; i++){
        xr += vecList[i].x;
    }
    for(int i = 0; i<sizeN; i++){
        yr += vecList[i].y;
    }

    dot vectorSum = {xr, yr, 0};
    return vectorSum;
}

dot vect_resultN( dot vecList[], int sizeN, float x1){
    float xr = 0.0;
    float yr = 0.0;
    float zr = 0.0;

    for(int i = 0; i<sizeN; i++){
        xr += vecList[i].x;
    }
    for(int i = 0; i<sizeN; i++){
        yr += vecList[i].y;
    }
    for(int i = 0; i<sizeN; i++){
        zr += vecList[i].z;
    }
    
    dot vectorSum = {xr, yr, zr};
    return vectorSum;
}

float escalar(float x1, float y1, float x2, float y2){
    return x1*x2 + y1*y2;
}

float escalar(float x1, float y1, float z1, float x2, float y2, float z2){
    return x1*x2+y1*y2+z1*z2;
}

dot crossProduct(float x1, float y1, float x2, float y2){
    dot productVector = {0, 0, x1*y2-x2*y1};
    return productVector;
}

dot crossProduct(float x1, float y1, float z1, float x2, float y2, float z2){
    dot productVector = {y1*z2-y2*z1, x2*z1-x1*z2, x1*y2-x2*y1};
    return productVector;
}

void vectFormatAndPlace(float x, float y, float z){
    cout<<x<<"i + "<<y<<"j + "<<z<<"k "<<endl;

    if(x == 0.0 && y == 0.0){
        if(z == 0.0){
            cout<<"El vector se encuentra en el origen del plano"<<endl;
        }else{
            cout<<"El vector se encuentra en el eje Z"<<endl;
        }
    }
    else if(x == 0.0 && z == 0.0){
        cout<<"El vector se encuentra en el eje Y"<<endl;
    }
    else if(x == 0.0){
        cout<<"El vector se encuentra en el plano ZY"<<endl;
    }
    else if(y == 0.0 && z == 0.0){
        cout<<"El vector se encuentra en el eje X "<<endl;
    }
    else if(y == 0.0){
        cout<<"El vector se encuentra en el plano XZ"<<endl;
    }
    else if(z == 0.0){
        cout<<"El vector se encuentra en el plano XY"<<endl;
    }
    else if(x > 0){

        if(y>0 && z>0){
            cout<<"El vector se encuentra en el 1er octante"<<endl;
        }
        else if(y>0 && z< 0){
            cout<<"El vector se encuentra en el 5to octante"<<endl;
        }
        else if(y<0 && z>0){
            cout<<"El vector se encuentra en el 4to octante"<<endl;
        }
        else if(y<0 && z<0){
            cout<<"El vector se encuentra en el 8vo octante"<<endl;
        }
    }
    else{

        if(y>0 && z>0){
            cout<<"El vector se encuentra en el 2do octante"<<endl;
        }
        else if(y>0 && z< 0){
            cout<<"El vector se encuentra en el 6to octante"<<endl;
        }
        else if(y<0 && z>0){
            cout<<"El vector se encuentra en el 3er octante"<<endl;
        }
        else if(y<0 && z<0){
            cout<<"El vector se encuentra en el 7mo octante"<<endl;
        }
    }      
}

void forcesSystem(dot vectList[], int sizeN){

    dot forceVector = vect_resultN(vectList, sizeN, 0.0);
    float xf = forceVector.x;
    float yf = forceVector.y;
    float zf = forceVector.z;

    float magnitude = points_distance(0.0, 0.0, 0.0, xf, yf, zf);
    float radians = acos(xf/(pow(xf, 2) + pow(yf, 2) + pow(zf, 2)));

    cout<<"La magnitud del vector fuerza es: "<<magnitude<<endl;
    cout<<"El angulo del vector fuerza es: "<<radians<<" radianes"<<endl;
}
