.syntax unified
	.align 2, 0
	.global task_poo_gauge_0
	.thumb
	.thumb_func
	.type task_poo_gauge_0, %function
task_poo_gauge_0: @ 080CC4CC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0x0
	movs r0, #0x00
	mov r8, r0
	movs r0, #0x00
	strh r0, [r4, #0x12]
	ldr r6, _080CC51C @ =0x09EF5B2C
	adds r0, r6, #0x0
	movs r1, #0x04
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080CC520 @ =0x097356F4
	bl AllocObjTiles
	str r0, [r4, #0x00]
	ldr r5, _080CC524 @ =0x09849B98
	adds r0, r5, #0x0
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	str r5, [r4, #0x0C]
	ldrh r0, [r4, #0x12]
	bl func_080CC488
	lsls r0, r0, #0x02
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x08]
	mov r0, r8
	strb r0, [r4, #0x10]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080CC51C: .4byte 0x09EF5B2C
_080CC520: .4byte 0x097356F4
_080CC524: .4byte 0x09849B98
.syntax divided
