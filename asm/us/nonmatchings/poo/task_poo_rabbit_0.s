.syntax unified
	.align 2, 0
	.global task_poo_rabbit_0
	.thumb
	.thumb_func
	.type task_poo_rabbit_0, %function
task_poo_rabbit_0: @ 080CE310
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	ldr r0, _080CE3CC @ =0x0001B700
	str r0, [r5, #0x28]
	movs r0, #0xB7
	lsls r0, r0, #0x09
	str r0, [r5, #0x2C]
	movs r0, #0x00
	str r0, [r5, #0x30]
	str r0, [r5, #0x34]
	str r0, [r5, #0x04]
	movs r6, #0x00
	movs r4, #0x00
	ldr r7, _080CE3D0 @ =0x096FD57C
_080CE32C:
	lsls r1, r4, #0x03
	adds r1, r1, r7
	ldr r0, [r1, #0x00]
	ldrh r1, [r1, #0x04]
	bl func_08003524
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	bcs _080CE342
	adds r6, r0, #0x0
_080CE342:
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x01
	bls _080CE32C
	adds r0, r6, #0x0
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	adds r1, r5, #0x0
	adds r1, #0xA8
	movs r0, #0x07
	str r0, [r1, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl func_080CE2C4
	adds r0, r5, #0x0
	adds r0, #0x24
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r0, #0x88
	strh r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r5, #0x08]
	adds r4, #0x2C
	adds r0, r4, #0x0
	movs r1, #0x01
	bl TaskPoolInit
	adds r1, r5, #0x0
	adds r1, #0x28
	movs r2, #0x80
	lsls r2, r2, #0x01
	adds r0, r4, #0x0
	bl func_080CC178
	adds r4, #0x14
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2C]
	ldr r3, [r5, #0x30]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	movs r1, #0x3B
	bl func_080D2E28
	adds r1, r5, #0x0
	adds r1, #0xAE
	strh r0, [r1, #0x00]
	ldrh r0, [r1, #0x00]
	movs r1, #0x00
	bl func_080D2E70
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CE3CC: .4byte 0x0001B700
_080CE3D0: .4byte 0x096FD57C
.syntax divided
