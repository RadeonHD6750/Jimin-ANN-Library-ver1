/*
	뉴런들을 모아 하나의 층을 만들어 동작한다.
	
	원래는 여기서 층간의 오류역전파를 계산하였다.
	하지만 하위 계층에서 계산하는 편이 좋음을 알았다.
	그래서 층에서의 오류역전파만 한다.
	
	작성자 서지민
*/

#include <iostream>
#include <thread>

#include "Neuron.h"

using namespace std;

class Neuron_Layer
{
	
	private:
	
	/**********************************************
					신경망 학습요소
	**********************************************/
	
	int Active_Function;
	double Learning_Rate;
	double Beta_Rate;
	
	public:
	
	/**********************************************
					신경망 구조
	**********************************************/
	
	Neuron *neuron_layer;
	
	int Layer_Length;
	int Input_Length;
	
	Neuron_Layer()
	{
		
	}
	
	~Neuron_Layer()
	{
		delete[] neuron_layer;
	}
	
	//신경망 구축하기
	void Build(int Active_Function,int Layer_Length, int Input_Length,double Learning_Rate, double Beta_Rate)
	{
		this->Active_Function=Active_Function;
		this->Layer_Length = Layer_Length;
		this->Input_Length = Input_Length;
		
		this->Learning_Rate = Learning_Rate;
		this->Beta_Rate = Beta_Rate;
		
		
		//Neuron Build
		neuron_layer = new Neuron[Layer_Length];
		
		for(int i=0;i<Layer_Length;i++)
		{
			neuron_layer[i].Build(Active_Function,Input_Length,Learning_Rate,Beta_Rate);
		}
		
	}
	
	void Set_Value(int Active_Function,double Learning_Rate,double Beta_Rate)
	{
		this->Active_Function = Active_Function;
		this->Learning_Rate = Learning_Rate;
		this->Beta_Rate = Beta_Rate;
		
		for(int i=0;i<Layer_Length;i++)
		{	
			neuron_layer[i].Set_Value(Active_Function,Learning_Rate,Beta_Rate);
		}
	}
	
	//초기화
	void Init()
	{
		for(int i=0;i<Layer_Length;i++)
		{
			neuron_layer[i].Init();
		}
	}
	
	/**********************************************
					신경망 전파함수
	**********************************************/
	
	double* Propagate(double Signal[])
	{
		double *Result = new double[Layer_Length];
		
		
		for(int i=0;i<Layer_Length;i++)
		{
			Result[i] = neuron_layer[i].Propagate(Signal);
		}
		
		return Result;
	}
	

	/**********************************************
					신경망 학습식
	**********************************************/
	
	//오류 역전파
	void BP_Update(double Error_Delta[])
	{
		
		for(int i=0;i<Layer_Length;i++)
		{
			neuron_layer[i].BP_Update(Error_Delta[i]);
		}
	}
	
	
	//Hebb Rule
	void Hebb_Update(double Signal[])
	{
		for(int i=0;i<Layer_Length;i++)
		{
			neuron_layer->Hebb_Update(Signal);
		}
		
	}
};