.syntax unified
	.align 2, 0
	.global mode_sio_btl_connect_1
	.thumb
	.thumb_func
	.type mode_sio_btl_connect_1, %function
mode_sio_btl_connect_1: @ 080AEC9C
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	ldr r4, _080AECC0 @ =0x02034B3C
	ldr r1, [r4, #0x00]
	movs r0, #0x04
	ldsb r0, [r1, r0]
	cmp r0, #0x01
	beq _080AECD4
	cmp r0, #0x01
	bgt _080AECC4
	cmp r0, #0x00
	beq _080AECCE
	b _080AEDF0
	.byte 0x00, 0x00
_080AECC0: .4byte 0x02034B3C
_080AECC4:
	cmp r0, #0x02
	beq _080AED18
	cmp r0, #0x03
	beq _080AED38
	b _080AEDF0
_080AECCE:
	bl func_080C54B4
	b _080AEDF0
_080AECD4:
	bl func_080C54B4
	ldr r1, [r4, #0x00]
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x04
	bgt _080AECEA
	b _080AEDF0
_080AECEA:
	ldr r0, _080AED0C @ =0x080C6009
	ldr r1, _080AED10 @ =0x080C60D9
	bl func_080C5DC0
	bl func_080C61D4
	ldr r2, _080AED14 @ =0x03006C78
	ldrh r0, [r2, #0x00]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	b _080AED28
	.byte 0x00, 0x00
_080AED0C: .4byte 0x080C6009
_080AED10: .4byte 0x080C60D9
_080AED14: .4byte 0x03006C78
_080AED18:
	ldr r0, _080AED34 @ =0x02039B60
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080AEDF0
	movs r0, #0x00
	strh r0, [r1, #0x02]
	bl func_080AEE84
_080AED28:
	ldr r1, [r4, #0x00]
	ldrb r0, [r1, #0x04]
	adds r0, #0x01
	strb r0, [r1, #0x04]
	b _080AEDF0
	.byte 0x00, 0x00
_080AED34: .4byte 0x02039B60
_080AED38:
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x04
	ble _080AEDF0
	ldr r0, _080AEDC0 @ =0x080C5D51
	ldr r1, _080AEDC4 @ =0x080C5D81
	bl func_080C5DC0
	bl func_080C5D00
	ldr r0, _080AEDC8 @ =0x0203AA00
	movs r1, #0x01
	strb r1, [r0, #0x00]
	ldr r0, _080AEDCC @ =0x0203AA90
	strb r1, [r0, #0x00]
	ldr r0, _080AEDD0 @ =0x0203AA8C
	strb r1, [r0, #0x00]
	ldr r1, _080AEDD4 @ =0x0203AA58
	movs r0, #0x06
	strb r0, [r1, #0x00]
	strb r0, [r1, #0x01]
	movs r1, #0x00
	ldr r0, _080AEDD8 @ =0x0203A9EC
	mov r8, r0
	ldr r3, _080AEDDC @ =0x0203A9F0
	mov r9, r3
	ldr r0, _080AEDE0 @ =0x09EF14DC
	mov r10, r0
	ldr r3, _080AEDE4 @ =0x0203AA60
	mov r12, r3
	movs r4, #0x00
	ldr r7, _080AEDE8 @ =0x0203AAE0
	ldr r6, _080AEDEC @ =0x0203AA30
_080AED80:
	movs r3, #0x00
	lsls r0, r1, #0x02
	adds r5, r1, #0x1
	adds r0, r0, r1
	lsls r0, r0, #0x02
	mov r1, r12
	adds r2, r0, r1
	adds r1, r0, r6
	adds r0, r0, r7
_080AED92:
	strb r4, [r2, #0x00]
	strb r4, [r0, #0x00]
	strb r4, [r1, #0x00]
	adds r2, #0x01
	adds r1, #0x01
	adds r0, #0x01
	adds r3, #0x01
	cmp r3, #0x13
	ble _080AED92
	adds r1, r5, #0x0
	cmp r1, #0x01
	ble _080AED80
	movs r0, #0x00
	mov r3, r8
	strh r0, [r3, #0x00]
	mov r1, r9
	strh r0, [r1, #0x00]
	mov r0, r10
	movs r1, #0x00
	bl func_080010CC
	b _080AEE10
	.byte 0x00, 0x00
_080AEDC0: .4byte 0x080C5D51
_080AEDC4: .4byte 0x080C5D81
_080AEDC8: .4byte 0x0203AA00
_080AEDCC: .4byte 0x0203AA90
_080AEDD0: .4byte 0x0203AA8C
_080AEDD4: .4byte 0x0203AA58
_080AEDD8: .4byte 0x0203A9EC
_080AEDDC: .4byte 0x0203A9F0
_080AEDE0: .4byte 0x09EF14DC
_080AEDE4: .4byte 0x0203AA60
_080AEDE8: .4byte 0x0203AAE0
_080AEDEC: .4byte 0x0203AA30
_080AEDF0:
	ldr r0, _080AEE20 @ =0x02034B3C
	ldr r1, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x08
	movs r3, #0xB6
	lsls r3, r3, #0x02
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	movs r0, #0x14
	str r0, [sp, #0x000]
	ldrb r0, [r1, #0x05]
	str r0, [sp, #0x004]
	movs r0, #0x42
	movs r1, #0x3F
	bl func_080664D8
_080AEE10:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080AEE20: .4byte 0x02034B3C
.syntax divided
