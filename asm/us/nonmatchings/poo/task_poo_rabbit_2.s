.syntax unified
	.align 2, 0
	.global task_poo_rabbit_2
	.thumb
	.thumb_func
	.type task_poo_rabbit_2, %function
task_poo_rabbit_2: @ 080CE5DC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	ldr r0, _080CE648 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x2C]
	asrs r0, r0, #0x08
	ldr r2, _080CE64C @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r9, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	movs r0, #0x10
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	mov r0, r9
	mov r1, r8
	movs r2, #0x30
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x00
	beq _080CE650
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CE6CE
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x4C
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0xAE
	ldrh r0, [r0, #0x00]
	movs r1, #0x00
	bl func_080D2E70
	movs r0, #0x00
	str r0, [r4, #0x04]
	b _080CE6CE
	.byte 0x00, 0x00
_080CE648: .4byte 0x0203C40C
_080CE64C: .4byte 0x0203C3F8
_080CE650:
	adds r7, r4, #0x0
	adds r7, #0x38
	adds r0, r7, #0x0
	bl TaskPoolUpdate
	ldr r0, [r4, #0x04]
	adds r5, r4, #0x0
	adds r5, #0x4C
	cmp r0, #0x00
	bne _080CE686
	ldr r0, _080CE6DC @ =0x09849CB8
	movs r1, #0x40
	bl LoadObjPalette
	str r0, [r4, #0x04]
	adds r0, r5, #0x0
	movs r1, #0x0A
	movs r2, #0x04
	movs r3, #0x30
	bl func_080122AC
	adds r0, r4, #0x0
	adds r0, #0xAE
	ldrh r0, [r0, #0x00]
	movs r1, #0x01
	bl func_080D2E70
_080CE686:
	ldr r1, [r4, #0x28]
	ldr r2, [r4, #0x2C]
	ldr r3, [r4, #0x30]
	adds r0, r5, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x04
	cmp r0, #0x00
	beq _080CE6A2
	adds r1, #0x01
_080CE6A2:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r6, [sp, #0x004]
	str r1, [sp, #0x008]
	ldr r1, [r4, #0x2C]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080CE6E0 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	mov r0, r9
	mov r1, r8
	bl DrawSprite
	adds r0, r7, #0x0
	bl TaskPoolDraw
_080CE6CE:
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CE6DC: .4byte 0x09849CB8
_080CE6E0: .4byte 0xFFFFEFFC
.syntax divided
