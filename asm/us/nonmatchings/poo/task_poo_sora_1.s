.syntax unified
	.align 2, 0
	.global task_poo_sora_1
	.thumb
	.thumb_func
	.type task_poo_sora_1, %function
task_poo_sora_1: @ 080CB68C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r5, r0, #0x0
	mov r8, r1
	ldr r6, _080CB6F8 @ =0x0203C420
	bl func_080CAA14
	str r0, [sp, #0x000]
	ldr r0, [r6, #0x00]
	mov r9, r0
	ldr r1, [r6, #0x04]
	mov r10, r1
	adds r7, r5, #0x0
	adds r7, #0x94
	ldr r0, [r7, #0x00]
	cmp r0, #0x01
	bls _080CB6B8
	b _080CB828
_080CB6B8:
	adds r0, r6, #0x0
	bl func_080CA9DC
	bl GetKeysHeld
	movs r4, #0xF0
	ands r4, r0
	cmp r4, #0x00
	beq _080CB71C
	ldr r0, [r6, #0x10]
	adds r0, #0x80
	str r0, [r6, #0x10]
	adds r0, r5, #0x0
	movs r1, #0x02
	movs r2, #0x01
	bl func_080CAA50
	ldr r0, [r6, #0x10]
	ldr r1, _080CB6FC @ =0x00000266
	cmp r0, r1
	ble _080CB6E4
	str r1, [r6, #0x10]
_080CB6E4:
	ldrh r0, [r5, #0x12]
	cmp r0, #0x00
	bne _080CB732
	ldrh r0, [r5, #0x16]
	cmp r0, #0x03
	beq _080CB700
	cmp r0, #0x07
	beq _080CB70E
	b _080CB732
	.byte 0x00, 0x00
_080CB6F8: .4byte 0x0203C420
_080CB6FC: .4byte 0x00000266
_080CB700:
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x00]
	bl m4aSongNumStart
	b _080CB732
_080CB70E:
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x02]
	bl m4aSongNumStart
	b _080CB732
_080CB71C:
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080CAA50
	ldr r0, [r6, #0x10]
	subs r0, #0x80
	str r0, [r6, #0x10]
	cmp r0, #0x00
	bge _080CB732
	str r4, [r6, #0x10]
_080CB732:
	ldr r3, _080CB79C @ =0x08121400
	ldrb r0, [r6, #0x14]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, [r6, #0x10]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x00]
	adds r0, r0, r1
	str r0, [r6, #0x00]
	ldrb r0, [r6, #0x14]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x04]
	adds r0, r0, r1
	str r0, [r6, #0x04]
	bl GetKeysPressed
	movs r2, #0x02
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	cmp r4, #0x00
	beq _080CB7A4
	adds r1, r5, #0x0
	adds r1, #0x98
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x94
	str r2, [r0, #0x00]
	ldr r1, _080CB7A0 @ =0x080CAD09
	mov r0, r8
	bl func_08000F8C
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x04]
	bl m4aSongNumStart
	b _080CB7E6
_080CB79C: .4byte 0x08121400
_080CB7A0: .4byte 0x080CAD09
_080CB7A4:
	bl GetKeysPressed
	movs r7, #0x01
	ands r7, r0
	cmp r7, #0x00
	beq _080CB7F0
	adds r0, r6, #0x0
	bl func_080CAB24
	ldr r0, _080CB7CC @ =0x0203C3D8
	strb r4, [r0, #0x00]
	bl func_080D2EB8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xB4
	beq _080CB7D0
	bl func_080C7BCC
	b _080CB7E6
_080CB7CC: .4byte 0x0203C3D8
_080CB7D0:
	adds r0, r5, #0x0
	adds r0, #0x98
	strh r4, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x94
	movs r0, #0x06
	str r0, [r1, #0x00]
	ldr r1, _080CB7EC @ =0x080CB1BD
	mov r0, r8
	bl func_08000F8C
_080CB7E6:
	adds r4, r5, #0x0
	adds r4, #0x08
	b _080CB83C
_080CB7EC: .4byte 0x080CB1BD
_080CB7F0:
	bl GetKeysPressed
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r1, r0
	adds r4, r5, #0x0
	adds r4, #0x08
	cmp r1, #0x00
	beq _080CB83C
	adds r0, r5, #0x0
	adds r0, #0x98
	strh r7, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x94
	movs r0, #0x08
	str r0, [r1, #0x00]
	ldr r1, _080CB824 @ =0x080CB5A9
	mov r0, r8
	bl func_08000F8C
	adds r0, r6, #0x0
	bl _080CA960
	strb r0, [r6, #0x14]
	b _080CB83C
	.byte 0x00, 0x00
_080CB824: .4byte 0x080CB5A9
_080CB828:
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CB83C
	movs r0, #0x00
	str r0, [r7, #0x00]
_080CB83C:
	adds r0, r6, #0x0
	bl func_080CBAB0
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080CB84C
	movs r0, #0x00
	str r0, [r6, #0x10]
_080CB84C:
	adds r0, r5, #0x0
	adds r1, r6, #0x0
	bl func_080CA8D4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CB864
	ldr r1, [r6, #0x10]
	movs r0, #0xE6
	muls r0, r1
	asrs r0, r0, #0x08
	str r0, [r6, #0x10]
_080CB864:
	adds r0, r6, #0x0
	mov r1, r9
	mov r2, r10
	bl func_080CA560
	adds r0, r6, #0x0
	bl func_080CFE34
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CB886
	mov r0, r9
	str r0, [r6, #0x00]
	mov r1, r10
	str r1, [r6, #0x04]
	movs r0, #0x00
	str r0, [r6, #0x10]
_080CB886:
	ldr r0, [r6, #0x08]
	ldr r1, [sp, #0x000]
	cmp r1, r0
	beq _080CB8B0
	ldr r0, [r6, #0x10]
	asrs r0, r0, #0x02
	str r0, [r6, #0x10]
	adds r0, r5, #0x0
	adds r0, #0x9C
	movs r1, #0x00
	str r1, [r0, #0x00]
	subs r0, #0x04
	strh r1, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x94
	movs r0, #0x04
	str r0, [r1, #0x00]
	ldr r1, _080CB8EC @ =0x080CAD09
	mov r0, r8
	bl func_08000F8C
_080CB8B0:
	adds r0, r5, #0x0
	adds r0, #0x38
	ldr r1, [r6, #0x00]
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	bl func_08012324
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x04]
	ldr r2, [r6, #0x08]
	adds r1, r1, r2
	bl func_080C9FA8
	adds r0, r4, #0x0
	bl AnimUpdate
	str r0, [r5, #0x20]
	adds r0, r5, #0x0
	adds r0, #0x24
	bl TaskPoolUpdate
	movs r0, #0x01
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080CB8EC: .4byte 0x080CAD09
.syntax divided
