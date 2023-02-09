/* ************************************************************************
> File Name:     stress_test.cpp
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Sun 16 Dec 2018 11:56:04 AM CST
> Description:

> Modify : Zhiheng
> 2022/12/22 
 ************************************************************************/

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <pthread.h>
#include <time.h>
#include <fstream>
#include "../skiplist.h"

#define NUM_THREADS 1
#define TEST_COUNT 1000000
SkipList<int, std::string> skipList(20);

void *insertElement(void* threadid) {
    long tid; 
    tid = (long)threadid;
    std::cout << tid << std::endl;  
    int tmp = TEST_COUNT/NUM_THREADS; 
	for (int i=tid*tmp, count=0; count<tmp; i++) {
        count++;
		skipList.insert_element(rand() % TEST_COUNT, "a"); 
	}
    pthread_exit(NULL);
}

void *getElement(void* threadid) {
    long tid; 
    tid = (long)threadid;
    std::cout << tid << std::endl;  
    int tmp = TEST_COUNT/NUM_THREADS; 
	for (int i=tid*tmp, count=0; count<tmp; i++) {
        count++;
		skipList.search_element(rand() % TEST_COUNT); 
	}
    pthread_exit(NULL);
}

void *updateElement(void* threadid) {
    long tid; 
    tid = (long)threadid;
    std::cout << tid << std::endl;  
    int tmp = TEST_COUNT/NUM_THREADS; 
	for (int i=tid*tmp, count=0; count<tmp; i++) {
        count++;
		skipList.update_element(rand() % TEST_COUNT, "a"); 
	}
    pthread_exit(NULL);
}

void *deleteElement(void* threadid) {
    long tid; 
    tid = (long)threadid;
    std::cout << tid << std::endl;  
    int tmp = TEST_COUNT/NUM_THREADS; 
	for (int i=tid*tmp, count=0; count<tmp; i++) {
        count++;
		skipList.delete_element(rand() % TEST_COUNT); 
	}
    pthread_exit(NULL);
}

int main() {
    srand (time(NULL));
    std::ofstream file_record;
    file_record.open("stress-test/test_record", std::ios::app);
    file_record << "TEST_COUNT : " << TEST_COUNT << " NUM_THREADS : " << NUM_THREADS <<std::endl;
    file_record.close();

    // Insert stress test
    {
        pthread_t threads[NUM_THREADS];
        int rc;
        int i;

        auto start = std::chrono::high_resolution_clock::now();

        for( i = 0; i < NUM_THREADS; i++ ) {
            rc = pthread_create(&threads[i], NULL, insertElement, (void *)i);

            if (rc) {
                std::cout << "Error:unable to create thread," << rc << std::endl;
                exit(-1);
            }
        }

        void *ret;
        for( i = 0; i < NUM_THREADS; i++ ) {
            if (pthread_join(threads[i], &ret) !=0 )  {
                perror("pthread_create() error"); 
                exit(3);
            }
        }
        auto finish = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = finish - start;
        file_record.open("stress-test/test_record", std::ios::app);
        file_record << "insert elapsed: " << elapsed.count() << std::endl;
        file_record.close();
        //std::cout << "insert elapsed:" << elapsed.count() << std::endl;
    }
    // skipList.displayList();

    // Get stress test
    {
        pthread_t threads[NUM_THREADS];
        int rc;
        int i;
        auto start = std::chrono::high_resolution_clock::now();

        for( i = 0; i < NUM_THREADS; i++ ) {
            //std::cout << "main() : creating thread, " << i << std::endl;
            rc = pthread_create(&threads[i], NULL, getElement, (void *)i);

            if (rc) {
                std::cout << "Error:unable to create thread," << rc << std::endl;
                exit(-1);
            }
        }

        void *ret;
        for( i = 0; i < NUM_THREADS; i++ ) {
            if (pthread_join(threads[i], &ret) !=0 )  {
                perror("pthread_create() error"); 
                exit(3);
            }
        }

        auto finish = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = finish - start;
        file_record.open("stress-test/test_record", std::ios::app);
        file_record << "get elapsed: " << elapsed.count() << std::endl;
        file_record.close();
        //std::cout << "get elapsed:" << elapsed.count() << std::endl;
    }

    // Update stress test
    {
        pthread_t threads[NUM_THREADS];
        int rc;
        int i;
        auto start = std::chrono::high_resolution_clock::now();

        for( i = 0; i < NUM_THREADS; i++ ) {
            //std::cout << "main() : creating thread, " << i << std::endl;
            rc = pthread_create(&threads[i], NULL, updateElement, (void *)i);

            if (rc) {
                std::cout << "Error:unable to create thread," << rc << std::endl;
                exit(-1);
            }
        }

        void *ret;
        for( i = 0; i < NUM_THREADS; i++ ) {
            if (pthread_join(threads[i], &ret) !=0 )  {
                perror("pthread_create() error"); 
                exit(3);
            }
        }

        auto finish = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = finish - start;
        file_record.open("stress-test/test_record", std::ios::app);
        file_record << "update elapsed: " << elapsed.count() << std::endl;
        file_record.close();
        //std::cout << "get elapsed:" << elapsed.count() << std::endl;
    }

    // Update stress test
    {
        pthread_t threads[NUM_THREADS];
        int rc;
        int i;
        auto start = std::chrono::high_resolution_clock::now();

        for( i = 0; i < NUM_THREADS; i++ ) {
            //std::cout << "main() : creating thread, " << i << std::endl;
            rc = pthread_create(&threads[i], NULL, deleteElement, (void *)i);

            if (rc) {
                std::cout << "Error:unable to create thread," << rc << std::endl;
                exit(-1);
            }
        }

        void *ret;
        for( i = 0; i < NUM_THREADS; i++ ) {
            if (pthread_join(threads[i], &ret) !=0 )  {
                perror("pthread_create() error"); 
                exit(3);
            }
        }

        auto finish = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = finish - start;
        file_record.open("stress-test/test_record", std::ios::app);
        file_record << "delete elapsed: " << elapsed.count() << std::endl;
        file_record.close();
        //std::cout << "get elapsed:" << elapsed.count() << std::endl;
    }
	pthread_exit(NULL);
    std::cout << "stress test finished!" << std::endl;
    return 0;

}
