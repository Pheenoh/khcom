.syntax unified
	.align 2, 0
	.global task_allmap_room_3
	.thumb
	.thumb_func
	.type task_allmap_room_3, %function
task_allmap_room_3: @ 080D39F4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	adds r4, #0x0C
	movs r5, #0x03
_080D3A08:
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080D3A12
	bl ReleaseObjTiles
_080D3A12:
	adds r4, #0x04
	subs r5, #0x01
	cmp r5, #0x00
	bge _080D3A08
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
