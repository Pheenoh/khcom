.syntax unified
	.align 2, 0
	.global task_poo_freeballoon_1
	.thumb
	.thumb_func
	.type task_poo_freeballoon_1, %function
task_poo_freeballoon_1: @ 080CC2B0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	adds r1, r7, #0x0
	adds r1, #0x90
	ldrh r2, [r1, #0x00]
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bls _080CC2EE
	subs r1, r2, #0x4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r1, #0x08
	ldr r0, [r7, #0x7C]
	subs r0, r0, r2
	str r0, [r7, #0x6C]
	adds r2, r7, #0x0
	adds r2, #0x80
	adds r0, r1, #0x0
	muls r0, r1
	lsls r0, r0, #0x08
	cmp r0, #0x00
	bge _080CC2E4
	adds r0, #0x1F
_080CC2E4:
	asrs r1, r0, #0x05
	ldr r0, [r2, #0x00]
	subs r0, r0, r1
	str r0, [r7, #0x70]
	b _080CC30E
_080CC2EE:
	adds r2, r7, #0x0
	adds r2, #0x94
	adds r1, r7, #0x0
	adds r1, #0x6C
	ldr r0, [r2, #0x00]
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x7C
	ldr r0, [r2, #0x00]
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
_080CC30E:
	adds r2, r7, #0x0
	adds r2, #0x90
	ldrh r1, [r2, #0x00]
	lsls r1, r1, #0x08
	ldr r0, [r7, #0x34]
	adds r0, r0, r1
	str r0, [r7, #0x24]
	ldrh r0, [r2, #0x00]
	adds r5, r0, #0x0
	muls r5, r0
	adds r0, r5, #0x0
	lsls r0, r0, #0x08
	cmp r0, #0x00
	bge _080CC32C
	adds r0, #0x1F
_080CC32C:
	asrs r1, r0, #0x05
	ldr r0, [r7, #0x38]
	subs r0, r0, r1
	str r0, [r7, #0x28]
	ldr r0, [r7, #0x6C]
	asrs r0, r0, #0x08
	ldr r1, _080CC3C8 @ =0x0203C40C
	ldrh r3, [r1, #0x00]
	subs r0, r0, r3
	adds r6, r7, #0x0
	adds r6, #0x8C
	strh r0, [r6, #0x00]
	ldr r1, [r7, #0x70]
	asrs r1, r1, #0x08
	ldr r0, [r7, #0x74]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080CC3CC @ =0x0203C3F8
	ldrh r2, [r0, #0x00]
	subs r1, r1, r2
	movs r0, #0x8E
	adds r0, r0, r7
	mov r12, r0
	strh r1, [r0, #0x00]
	ldr r0, [r7, #0x24]
	asrs r0, r0, #0x08
	subs r0, r0, r3
	adds r5, r7, #0x0
	adds r5, #0x44
	strh r0, [r5, #0x00]
	ldr r1, [r7, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r7, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	subs r1, r1, r2
	adds r4, r7, #0x0
	adds r4, #0x46
	strh r1, [r4, #0x00]
	movs r1, #0x00
	ldsh r0, [r6, r1]
	mov r2, r12
	movs r3, #0x00
	ldsh r1, [r2, r3]
	bl func_080CC284
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080CC398
	adds r0, r7, #0x0
	adds r0, #0x54
	bl AnimUpdate
_080CC398:
	str r0, [r7, #0x50]
	movs r1, #0x00
	ldsh r0, [r5, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	bl func_080CC284
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080CC3B6
	adds r0, r7, #0x0
	adds r0, #0x0C
	bl AnimUpdate
_080CC3B6:
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x08]
	cmp r0, #0x00
	bne _080CC3D0
	ldr r0, [r7, #0x50]
	cmp r0, #0x00
	bne _080CC3D0
	movs r0, #0x00
	b _080CC3D2
_080CC3C8: .4byte 0x0203C40C
_080CC3CC: .4byte 0x0203C3F8
_080CC3D0:
	movs r0, #0x01
_080CC3D2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
