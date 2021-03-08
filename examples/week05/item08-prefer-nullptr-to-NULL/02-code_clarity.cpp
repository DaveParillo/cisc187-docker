/*
 * Key Idea:
 *
 *   Using nullptr improves code clarity especially when auto variables are
 *   involved.
 */

int* findRecord() {
  return nullptr;
}

int main() {
  // If you don’t happen to know (or can’t easily find out) what findRecord returns, 
  // it may not be clear whether result is a pointer type or an integral type. 
  //
  // After all, 0 (what result is tested against) could go either way. 

  {
    auto result = findRecord( /* arguments */ );

    if (result == 0) {
    }
  }


  // If you see the following, on the other hand ...
  {
    auto result = findRecord( /* arguments */ );

    if (result == nullptr) {
    }
    // there’s no ambiguity: result must be a pointer type.
  }

}
