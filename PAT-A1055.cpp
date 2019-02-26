// PAT-1055

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int case_num, people_num;

struct People {
    char name[20];
    int age;
    long wealth;
} peo[100010];

bool cmp(People a, People b)
{
    if (a.wealth != b.wealth)
        return a.wealth > b.wealth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return strcmp(a.name, b.name) < 0;
}

int main()
{
    scanf("%d%d", &people_num, &case_num);
    for (int i = 0; i < people_num; i++) {
        scanf("%s%d%ld", peo[i].name, &peo[i].age, &peo[i].wealth);
    }
    std::sort(peo, peo+people_num, cmp);
    for (int i = 0; i < case_num; i++) {
        int M, min_age, max_age;
        bool find = false;
        scanf("%d%d%d", &M, &min_age, &max_age);
        printf("Case #%d\n", i+1);
        for (int j = 0; j < people_num && M; j++) {
            if (peo[j].age >= min_age && peo[j].age <= max_age) {
                find = true;
                M--;
                printf("%s %d %ld\n", peo[j].name, peo[j].age, peo[j].wealth);
            }
        }
        if(!find)
            printf("None\n");
    }
}
