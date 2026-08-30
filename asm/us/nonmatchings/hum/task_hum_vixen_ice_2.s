.syntax unified
	.align 2, 0
	.global task_hum_vixen_ice_2
	.thumb
	.thumb_func
	.type task_hum_vixen_ice_2, %function
task_hum_vixen_ice_2: @ 080558D8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r5, r0, #0x0
	ldr r0, [r5, #0x24]
	ldrb r0, [r0, #0x01]
	cmp r0, #0x00
	beq _08055962
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	adds r7, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r0, [r5, #0x24]
	ldr r2, [r0, #0x04]
	ldr r3, [r0, #0x08]
	movs r0, #0x00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	adds r1, r5, #0x0
	adds r1, #0x8C
	ldr r0, _08055930 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r1, [r1, #0x00]
	ldr r0, [r3, #0x24]
	muls r0, r1
	asrs r2, r0, #0x08
	ldrb r0, [r3, #0x18]
	adds r6, r4, #0x0
	cmp r0, #0x00
	bne _08055926
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	ble _08055934
_08055926:
	ldrb r0, [r3, #0x18]
	adds r1, r2, #0x0
	movs r3, #0x01
	b _0805593A
	.byte 0x00, 0x00
_08055930: .4byte 0x02039B84
_08055934:
	ldrb r0, [r3, #0x18]
	adds r1, r2, #0x0
	movs r3, #0x00
_0805593A:
	bl func_08002CB4
	adds r4, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r3, [r5, #0x04]
	ldr r2, [r5, #0x08]
	str r2, [sp, #0x000]
	str r4, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x04
	str r2, [sp, #0x008]
	ldr r2, _0805596C @ =0x0000FFFF
	str r2, [sp, #0x00C]
	adds r2, r7, #0x0
	bl func_080023E0
_08055962:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805596C: .4byte 0x0000FFFF
.syntax divided
