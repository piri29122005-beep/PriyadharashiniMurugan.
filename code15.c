#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

struct package {
    char* id;
    int weight;
};

typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;


// 1. Print all packages
void print_all_packages(town t) {
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);

        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}


// 2. Send acceptable packages
void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {

    post_office* src = &source->offices[source_office_index];
    post_office* tgt = &target->offices[target_office_index];

    int count = 0;

    // count acceptable
    for (int i = 0; i < src->packages_count; i++) {
        int w = src->packages[i].weight;
        if (w >= tgt->min_weight && w <= tgt->max_weight) {
            count++;
        }
    }

    // expand target
    tgt->packages = realloc(tgt->packages, (tgt->packages_count + count) * sizeof(package));

    int tgt_index = tgt->packages_count;

    package* remaining = malloc(src->packages_count * sizeof(package));
    int rem_index = 0;

    // move packages
    for (int i = 0; i < src->packages_count; i++) {
        int w = src->packages[i].weight;

        if (w >= tgt->min_weight && w <= tgt->max_weight) {
            tgt->packages[tgt_index++] = src->packages[i];
        } else {
            remaining[rem_index++] = src->packages[i];
        }
    }

    tgt->packages_count += count;

    free(src->packages);
    src->packages = remaining;
    src->packages_count = rem_index;
}


// 3. Town with most packages
town town_with_most_packages(town* towns, int towns_count) {
    int max_packages = 0;
    int index = 0;

    for (int i = 0; i < towns_count; i++) {
        int total = 0;

        for (int j = 0; j < towns[i].offices_count; j++) {
            total += towns[i].offices[j].packages_count;
        }

        if (total > max_packages) {
            max_packages = total;
            index = i;
        }
    }

    return towns[index];
}


// 4. Find town
town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}


int main() {
    int towns_count;
    scanf("%d", &towns_count);

    town* towns = malloc(sizeof(town) * towns_count);

    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);

        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);

        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d",
                  &towns[i].offices[j].packages_count,
                  &towns[i].offices[j].min_weight,
                  &towns[i].offices[j].max_weight);

            towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);

            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);

    while (queries--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char town_name[MAX_STRING_LENGTH];
            scanf("%s", town_name);

            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
        }
        else if (type == 2) {
            char source_name[MAX_STRING_LENGTH], target_name[MAX_STRING_LENGTH];
            int source_index, target_index;

            scanf("%s %d %s %d", source_name, &source_index, target_name, &target_index);

            town* source = find_town(towns, towns_count, source_name);
            town* target = find_town(towns, towns_count, target_name);

            send_all_acceptable_packages(source, source_index, target, target_index);
        }
        else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }

    return 0;
}