#ifndef _GRID_TASK_H_
#define _GRID_TASK_H_

#include "mpi.h"

#include <vector>

typedef enum
{
    DEAD_PROC          = -999,
    DATA_REDUNDANCY    = -998,
    COMPUTE_REDUNDANCY = -997,
    BORDER             = MPI_PROC_NULL
} grid_task_e;

typedef struct task task_t;

struct task
{
    int     x;                   // Grid coordinates
    int     y;                   // Grid coordinates
    int     rank;                // Assigned proc rank
    int     top;                 // Neighbor top
    int     bottom;              // Neighbor down
    int     left;                // Neighbor left
    int     right;               // Neighbor right
    int     redundancy_capacity; // Capacity
    int     redundancy_counter;  // Actual size
    int     real_capacity;       // Capacity
    int     real_counter;        // Actual size
    double *local_grid;          // Local-grid
    double *local_newgrid;       // Local-grid (new)

    std::vector<task_t *> real_task;
    std::vector<task_t *> redundancy_task;
};

class GridTask
{
    public:
        GridTask(const int cols,
                 const int rows,
                 const int nx,
                 const int ny,
                 const int commsize);

        ~GridTask();

        /*********************************************************************/
        /* Main intialize method                                             */
        /*********************************************************************/
        void init(grid_task_e mode);
        /*********************************************************************/
        /* Main kill process's task method                                   */
        /*********************************************************************/
        void killRank(const int killed);
        /*********************************************************************/
        /* Main repair method                                                */
        /*********************************************************************/
        void repair();
        /*********************************************************************/
        /* Neighbor setters                                                  */
        /*********************************************************************/
        void neighborTopSet(const int x, const int y);
        void neighborBottomSet(const int x, const int y);
        void neighborLeftSet(const int x, const int y);
        void neighborRightSet(const int x, const int y);
        /*********************************************************************/
        /* Task getters                                                      */
        /*********************************************************************/
        task_t *taskGet(const int rank);
        /*********************************************************************/
        /* Redundancy task setter                                            */
        /*********************************************************************/
        void redundancyTaskSet(const int rank, const int row, const int col);
        /*********************************************************************/
        /* Raal task setter                                                  */
        /*********************************************************************/
        int realTaskGet(const task_t *my_task, task_t **tasks);
        /*********************************************************************/
        /* Show/print method                                                 */
        /*********************************************************************/
        void show();

    private:
        grid_task_e mode;  // DATA or COMPUTE - redundancy

        int cols;          // Amount of cells by x (for whole grid)
        int rows;          // Amount of cells by y (for whole grid)
        int cols_per_proc; // Amount of processes by x (for whole grid)
        int rows_per_proc; // Amount of processes by y (for whole grid)
        int cols_per_task; // Amount of cells by x (per task)
        int rows_per_task; // Amount of cells by y (per task)
        int proc_per_node; // Amount of processes per node

        std::vector<std::vector<task_t> > tasks;
};

#endif /* _GRID_TASK_H_ */