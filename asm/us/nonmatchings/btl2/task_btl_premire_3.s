.syntax unified
	.align 2, 0
	.global task_btl_premire_3
	.thumb
	.thumb_func
	.type task_btl_premire_3, %function
task_btl_premire_3: @ 08031AC4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x10]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x14]
	bl ReleaseObjPalette
	ldr r0, _08031AE8 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08031AE8: .4byte 0x02039B84
.syntax divided
