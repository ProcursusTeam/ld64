#pragma once

struct vm_statistics {
  int free_count;
  int active_count;
  int inactive_count;
  int wire_count;
  int zero_fill_count;
  int reactivations;
  int pageins;
  int pageouts;
  int faults;
  int cow_faults;
  int lookups;
  int hits;
  int purgeable_count;
  int purges;
  int speculative_count;
};

typedef struct vm_statistics vm_statistics_data_t;
