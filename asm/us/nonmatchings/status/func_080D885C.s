.syntax unified
	.align 2, 0
	.global func_080D885C
	.thumb
	.thumb_func
	.type func_080D885C, %function
func_080D885C: @ 080D885C
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D8308
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080D8888
	bl func_080D8308
	adds r1, r0, #0x0
	ldr r0, [r4, #0x0C]
	ldrh r2, [r0, #0x00]
	movs r0, #0x54
	muls r0, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl func_0811D5EC
	adds r0, #0x28
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _080D888A
_080D8888:
	movs r0, #0x28
_080D888A:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
