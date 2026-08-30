.syntax unified
	.align 2, 0
	.global func_080AA764
	.thumb
	.thumb_func
	.type func_080AA764, %function
func_080AA764: @ 080AA764
	movs r3, #0x00
	adds r1, r0, #0x0
	movs r2, #0x09
_080AA76A:
	ldrh r0, [r1, #0x00]
	adds r3, r3, r0
	adds r1, #0x02
	subs r2, #0x01
	cmp r2, #0x00
	bge _080AA76A
	adds r0, r3, #0x0
	bx lr
	.byte 0x00, 0x00
.syntax divided
