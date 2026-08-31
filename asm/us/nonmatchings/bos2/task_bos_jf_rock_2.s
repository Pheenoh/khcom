.syntax unified
	.align 2, 0
	.global task_bos_jf_rock_2
	.thumb
	.thumb_func
	.type task_bos_jf_rock_2, %function
task_bos_jf_rock_2: @ 080C1204
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	ldr r0, [r5, #0x00]
	mov r8, r0
	movs r1, #0xAD
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080C1292
	mov r2, r8
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080C1240
	ldr r1, [r5, #0x30]
	ldr r0, _080C123C @ =0x000259FF
	cmp r1, r0
	ble _080C124A
	b _080C125A
	.byte 0x00, 0x00
_080C123C: .4byte 0x000259FF
_080C1240:
	ldr r1, [r5, #0x30]
	movs r0, #0xD9
	lsls r0, r0, #0x09
	cmp r1, r0
	ble _080C125A
_080C124A:
	ldr r0, [r5, #0x34]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r7, #0xFD
	lsls r7, r7, #0x08
	b _080C1260
_080C125A:
	movs r6, #0x80
	lsls r6, r6, #0x03
	ldr r7, _080C1330 @ =0x0000FFF5
_080C1260:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x30]
	ldr r3, [r5, #0x34]
	ldr r0, [r5, #0x38]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r5, #0x0C]
	ldr r3, [r5, #0x04]
	ldr r4, [r5, #0x08]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	str r7, [sp, #0x00C]
	bl DrawSprite
_080C1292:
	movs r3, #0xBE
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080C130C
	mov r4, r8
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	movs r6, #0x80
	lsls r6, r6, #0x03
	cmp r0, #0x00
	bne _080C12B8
	movs r0, #0x01
	orrs r6, r0
_080C12B8:
	mov r4, sp
	adds r4, #0x12
	movs r7, #0xB8
	lsls r7, r7, #0x01
	adds r0, r5, r7
	ldr r2, [r0, #0x00]
	movs r1, #0xBA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r3, [r0, #0x00]
	adds r7, #0x08
	adds r0, r5, r7
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	movs r3, #0xB6
	lsls r3, r3, #0x01
	adds r2, r5, r3
	ldr r2, [r2, #0x00]
	movs r4, #0xB2
	lsls r4, r4, #0x01
	adds r3, r5, r4
	ldr r3, [r3, #0x00]
	subs r7, #0x10
	adds r4, r5, r7
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, _080C1334 @ =0x0000FFF2
	str r4, [sp, #0x00C]
	bl DrawSprite
_080C130C:
	movs r1, #0xCA
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080C1322
	movs r2, #0xC0
	lsls r2, r2, #0x01
	adds r0, r5, r2
	bl TaskPoolDraw
_080C1322:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C1330: .4byte 0x0000FFF5
_080C1334: .4byte 0x0000FFF2
.syntax divided
