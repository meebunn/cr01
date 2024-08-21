avl_t *make_rotation(avl_t *t) {
//   int h_l = depth(t->left);
//   int h_r = depth(t->right);
//   // printf("Make Rotation for %d : %d %d\n",t->data,h_l,h_r);
//   if (h_l > h_r) {
//     h_l = depth(t->left->left);
//     h_r = depth(t->left->right);
//     if(h_l > h_r){
//       //left left = right rotation
//       // printf("left left\n");
//       return right_rotation(t);
//     }
//     // printf("left right\n");
//     t->left = left_rotation(t->left);
//     t->height = new_depth(t);
//     return right_rotation(t);
//   }
//   if(h_l < h_r){
//     h_l = depth(t->right->left);
//     h_r = depth(t->right->right);
//     if(h_l < h_r){
//       //right right = left rotation
//       // printf("right right\n");
//       return left_rotation(t);
//     }
//     // printf("right left\n");
//     t->right = right_rotation(t->right);
//     t->height = new_depth(t);
//     return left_rotation(t);
//   }
// }
