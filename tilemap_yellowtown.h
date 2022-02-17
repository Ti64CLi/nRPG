#ifndef __TILEMAP_YELLOWTOWN_H__
#define __TILEMAP_YELLOWTOWN_H__

#include <libndls.h>

#define TILEMAP_WIDTH 36
#define TILEMAP_HEIGHT 26
#define TILEMAP_SIZE (TILEMAP_WIDTH * TILEMAP_HEIGHT)

uint16_t tilemap_yellowtown[TILEMAP_SIZE] = {470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 484, 485, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471,
                                             478, 479, 328, 329, 328, 329, 328, 329, 486, 487, 1, 1, 486, 487, 486, 476, 477, 476, 477, 476, 477, 476, 477, 476, 477, 476, 477, 487, 486, 487, 486, 487, 486, 487, 478, 479,
                                             470, 471, 30, 475, 474, 475, 474, 475, 5, 5, 1, 1, 1, 1, 485, 468, 469, 468, 469, 468, 469, 468, 469, 468, 469, 470, 471, 484, 6, 176, 435, 436, 178, 23, 470, 471,
                                             478, 479, 480, 481, 528, 529, 530, 531, 532, 5, 1, 280, 281, 282, 466, 329, 328, 329, 487, 478, 479, 486, 626, 627, 628, 629, 487, 6, 1, 184, 450, 451, 186, 1, 478, 479,
                                             470, 471, 30, 475, 536, 537, 538, 539, 540, 541, 542, 288, 289, 290, 474, 475, 474, 475, 485, 470, 632, 633, 634, 635, 636, 637, 638, 639, 176, 192, 431, 431, 186, 485, 470, 471,
                                             478, 479, 480, 481, 544, 545, 546, 547, 548, 549, 550, 288, 289, 290, 482, 483, 482, 501, 14, 630, 640, 641, 642, 643, 644, 645, 646, 659, 184, 172, 430, 431, 186, 1, 478, 479,
                                             470, 471, 30, 475, 552, 553, 554, 555, 556, 557, 558, 575, 289, 290, 1, 4, 1, 22, 22, 115, 648, 649, 650, 651, 652, 653, 654, 655, 184, 431, 172, 172, 186, 485, 470, 471,
                                             478, 479, 482, 39, 560, 561, 562, 563, 564, 565, 566, 559, 289, 290, 1, 3, 1, 8, 9, 124, 656, 657, 658, 647, 660, 661, 662, 663, 184, 431, 279, 279, 186, 1, 478, 479,
                                             470, 471, 35, 46, 568, 585, 570, 571, 572, 573, 574, 567, 289, 290, 1, 1, 4, 16, 17, 1, 124, 10, 280, 281, 282, 1, 1, 1, 2, 2, 253, 253, 2, 485, 470, 471,
                                             478, 479, 102, 1, 280, 281, 281, 281, 281, 281, 281, 302, 289, 54, 281, 281, 281, 281, 281, 281, 281, 281, 302, 289, 303, 282, 1, 12, 12, 1, 278, 278, 1, 1, 478, 479,
                                             470, 471, 240, 1, 288, 289, 289, 289, 582, 289, 289, 289, 289, 289, 289, 289, 289, 582, 289, 289, 289, 289, 289, 289, 289, 290, 1, 1, 4, 4, 1, 1, 1, 485, 470, 471,
                                             478, 479, 93, 1, 296, 578, 579, 580, 581, 297, 310, 289, 289, 297, 578, 579, 580, 581, 297, 297, 297, 297, 297, 297, 297, 298, 1, 1, 1, 1, 466, 467, 466, 467, 478, 479,
                                             470, 471, 240, 14, 1, 594, 595, 596, 597, 1, 288, 289, 290, 14, 594, 595, 596, 597, 1, 1, 1, 14, 600, 601, 14, 1, 1, 12, 12, 1, 474, 475, 474, 31, 470, 471,
                                             478, 479, 93, 15, 14, 602, 603, 604, 605, 598, 288, 289, 290, 15, 602, 603, 604, 605, 598, 1, 1, 15, 608, 609, 15, 1, 1, 1, 4, 4, 480, 481, 464, 465, 478, 479,
                                             470, 471, 240, 15, 439, 610, 611, 612, 613, 606, 288, 289, 290, 439, 610, 611, 612, 613, 606, 1, 1, 22, 616, 617, 22, 1, 1, 1, 1, 1, 474, 31, 470, 471, 470, 471,
                                             478, 479, 93, 22, 46, 618, 584, 620, 621, 614, 288, 289, 290, 46, 618, 584, 620, 621, 614, 8, 9, 1, 280, 282, 1, 8, 9, 1, 462, 463, 464, 465, 478, 479, 478, 479,
                                             470, 471, 240, 4, 1, 280, 281, 281, 281, 590, 302, 289, 303, 281, 281, 281, 281, 282, 622, 16, 17, 280, 302, 303, 282, 16, 17, 118, 470, 471, 470, 471, 470, 471, 470, 471,
                                             478, 479, 94, 1, 4, 288, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 289, 303, 281, 281, 281, 302, 289, 289, 303, 282, 4, 1, 478, 479, 478, 479, 478, 479, 478, 479,
                                             470, 471, 484, 1, 1, 296, 297, 297, 297, 297, 297, 297, 297, 297, 297, 297, 310, 289, 289, 311, 297, 297, 297, 297, 297, 298, 1, 118, 470, 471, 470, 471, 470, 471, 470, 471,
                                             478, 479, 462, 463, 1, 1, 1, 1, 466, 467, 462, 463, 462, 463, 466, 467, 296, 297, 297, 298, 462, 463, 462, 463, 462, 463, 466, 467, 478, 479, 478, 479, 478, 479, 478, 479,
                                             470, 471, 470, 471, 484, 1, 1, 1, 474, 31, 470, 471, 470, 471, 30, 475, 1, 1, 1, 485, 470, 471, 470, 471, 470, 471, 30, 31, 470, 471, 470, 471, 470, 471, 470, 471,
                                             478, 479, 478, 479, 462, 463, 462, 463, 464, 465, 478, 479, 478, 479, 464, 465, 462, 463, 462, 463, 478, 479, 478, 479, 478, 479, 464, 465, 478, 479, 478, 479, 478, 479, 478, 479,
                                             470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471,
                                             478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479,
                                             470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471, 470, 471,
                                             478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479, 478, 479};

#endif