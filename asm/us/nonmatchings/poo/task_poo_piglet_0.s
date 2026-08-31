.syntax unified
	.align 2, 0
	.global task_poo_piglet_0
	.thumb
	.thumb_func
	.type task_poo_piglet_0, %function
task_poo_piglet_0: @ 080CD89C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	ldr r0, _080CD958 @ =0x0002A500
	str r0, [r6, #0x28]
	ldr r0, _080CD95C @ =0x00021100
	str r0, [r6, #0x2C]
	movs r1, #0x00
	str r1, [r6, #0x30]
	adds r0, r6, #0x0
	adds r0, #0xA8
	str r1, [r0, #0x00]
	adds r0, #0x04
	strh r1, [r0, #0x00]
	str r1, [r6, #0x04]
	movs r5, #0x00
	movs r4, #0x00
	ldr r7, _080CD960 @ =0x096FD4BC
_080CD8BE:
	lsls r1, r4, #0x03
	adds r1, r1, r7
	ldr r0, [r1, #0x00]
	ldrh r1, [r1, #0x04]
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r5, r0
	bcs _080CD8D4
	adds r5, r0, #0x0
_080CD8D4:
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x03
	bls _080CD8BE
	adds r0, r5, #0x0
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r6, #0x00]
	adds r5, r6, #0x0
	adds r5, #0x0C
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	movs r4, #0x00
	movs r0, #0x04
	strh r0, [r6, #0x26]
	adds r0, r6, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080CD854
	adds r0, r6, #0x0
	adds r0, #0x24
	strb r4, [r0, #0x00]
	adds r0, r5, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x08]
	adds r4, r6, #0x0
	adds r4, #0x94
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	ldr r1, _080CD964 @ =0x09EF4928
	adds r2, r6, #0x0
	adds r2, #0x28
	adds r0, r4, #0x0
	bl TaskCreate
	movs r0, #0x00
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CD950
	adds r0, r6, #0x0
	adds r0, #0x38
	movs r1, #0x36
	bl func_080D2E28
	adds r1, r6, #0x0
	adds r1, #0xB4
	strh r0, [r1, #0x00]
	ldrh r0, [r1, #0x00]
	movs r1, #0x00
	bl func_080D2E70
_080CD950:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CD958: .4byte 0x0002A500
_080CD95C: .4byte 0x00021100
_080CD960: .4byte 0x096FD4BC
_080CD964: .4byte 0x09EF4928
.syntax divided
