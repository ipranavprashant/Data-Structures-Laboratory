#include <stdio.h>

#define MAX_EMPLOYEES 103


int teams[MAX_EMPLOYEES + 1]; // team ID for each employee
int team_sizes[MAX_EMPLOYEES + 1]; // size of each team
int num_teams = 0; // number of teams formed

void create_team(int a, int b) {
    // If both employees are already on a team, merge the teams
    if (teams[a] != 0 && teams[b] != 0) {
        if (teams[a] == teams[b]) {
            return; // employees are already on the same team
        } else {
            int old_team_id = teams[a];
            int new_team_id = teams[b];
            for (int i = 1; i <= MAX_EMPLOYEES; i++) {
                if (teams[i] == old_team_id) {
                    teams[i] = new_team_id;
                    team_sizes[new_team_id]++;
                }
            }
            team_sizes[old_team_id] = 0;
            num_teams--;
        }
    }
    // If only one employee is on a team, add the other employee to the same team
    else if (teams[a] != 0) {
        teams[b] = teams[a];
        team_sizes[teams[a]]++;
    } else if (teams[b] != 0) {
        teams[a] = teams[b];
        team_sizes[teams[b]]++;
    }
    // If neither employee is on a team, create a new team
    else {
        num_teams++;
        teams[a] = num_teams;
        teams[b] = num_teams;
        team_sizes[num_teams] = 2;
    }
}

int count_possible_groups() {
    int count = 0;
    for (int i = 1; i <= num_teams; i++) {
        for (int j = i + 1; j <= num_teams; j++) {
            count += team_sizes[i] * team_sizes[j];
        }
    }
    if(count==0)
    return -1;
    else
    return count;
}

/*int is_valid_group(int x, int y) {
    if (teams[x] == 0 || teams[y] == 0) {
        return 0; // at least one employee is not on a team
    } else if (teams[x] == teams[y]) {
        return -1; // employees are already on the same team
    } else {
        return 1; // employees are on different teams
    }
}*/

int is_valid_group(int x, int y) {
    if (teams[x] == 0 || teams[y] == 0) {
        return -1;
    } else if (teams[x] == teams[y]) {
        return -1;
    } else {
        return 1;
    }
}




int main() {
    char command;
    int a, b;

    while (1) {
        scanf("%c", &command);
        if (command == 't') {
            scanf("%d %d", &a, &b);
            create_team(a, b);
        } else if (command == 'T') {
            printf("%d\n", num_teams);
        } else if (command == 'd') {
            printf("%d\n", count_possible_groups());
        } else if (command == 'v') {
            scanf("%d %d", &a, &b);
            if (a < b) {
                printf("%d\n", is_valid_group(a, b));
            } 
            else {
            int ans=is_valid_group(a, b);
            ans=-ans;
               printf("%d\n", ans);
            }
        } else if (command == 'e') {
            break;
        }
    }

    return 0;
}

