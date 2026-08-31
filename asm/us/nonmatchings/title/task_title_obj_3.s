.syntax unified
	.align 2, 0
	.global task_title_obj_3
	.thumb
	.thumb_func
	.type task_title_obj_3, %function
task_title_obj_3: @ 080D6764
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	movs r7, #0x00
	movs r6, #0x02
_080D676E:
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	adds r0, r5, #0x4
	adds r0, r0, r7
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	adds r4, #0x18
	adds r7, #0x18
	subs r6, #0x01
	cmp r6, #0x00
	bge _080D676E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
