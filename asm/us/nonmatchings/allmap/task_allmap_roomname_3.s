.syntax unified
	.align 2, 0
	.global task_allmap_roomname_3
	.thumb
	.thumb_func
	.type task_allmap_roomname_3, %function
task_allmap_roomname_3: @ 080D3EB8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x18
	bl func_08065AE0
	adds r4, #0xC8
	ldr r0, [r4, #0x00]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
