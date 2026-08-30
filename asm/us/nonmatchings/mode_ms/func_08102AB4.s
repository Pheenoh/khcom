.syntax unified
	.align 2, 0
	.global func_08102AB4
	.thumb
	.thumb_func
	.type func_08102AB4, %function
func_08102AB4: @ 08102AB4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x004]
	movs r3, #0x00
	ldr r7, _08102B04 @ =0x020358C8
	mov r9, r3
	ldr r0, _08102B08 @ =0x08F70AB0
	mov r10, r0
_08102AD6:
	ldr r1, _08102B0C @ =0x02035B58
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
	lsls r0, r2, #0x01
	adds r0, r0, r1
	ldrh r4, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x08
	adds r1, r0, #0x0
	adds r0, r4, #0x0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _08102B10
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r0, r0, r7
	adds r0, #0x46
	movs r1, #0x01
	b _08102B1A
	.byte 0x00, 0x00
_08102B04: .4byte 0x020358C8
_08102B08: .4byte 0x08F70AB0
_08102B0C: .4byte 0x02035B58
_08102B10:
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r0, r0, r7
	adds r0, #0x46
_08102B1A:
	strb r1, [r0, #0x00]
	lsls r6, r3, #0x10
	asrs r6, r6, #0x10
	lsls r5, r6, #0x03
	adds r5, r5, r6
	lsls r5, r5, #0x03
	adds r1, r5, r7
	mov r8, r1
	mov r0, r8
	adds r0, #0x47
	mov r2, r9
	strb r2, [r0, #0x00]
	ldr r1, _08102D48 @ =0x00000FFF
	adds r0, r1, #0x0
	ands r4, r0
	movs r0, #0x34
	muls r4, r0
	mov r0, r10
	adds r0, #0x08
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x20
	bl func_08002A14
	mov r2, r8
	str r0, [r2, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	mov r0, r10
	adds r0, #0x04
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x02
	bl func_080026A4
	adds r1, r7, #0x4
	adds r1, r5, r1
	str r0, [r1, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x08
	adds r1, r5, r1
	add r4, r10
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
	adds r4, #0x2A
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x05
	ldr r1, _08102D4C @ =0x09A3DB1C
	adds r0, r0, r1
	movs r1, #0x20
	bl func_08002A14
	adds r1, r7, #0x0
	adds r1, #0x0C
	adds r1, r5, r1
	str r0, [r1, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _08102D50 @ =0x099A4B9A
	movs r1, #0xEC
	lsls r1, r1, #0x05
	bl func_080026A4
	adds r1, r7, #0x0
	adds r1, #0x10
	adds r1, r5, r1
	str r0, [r1, #0x00]
	adds r0, r7, #0x0
	adds r0, #0x14
	adds r0, r5, r0
	mov r1, r9
	str r1, [r0, #0x00]
	adds r4, r7, #0x0
	adds r4, #0x18
	adds r4, r5, r4
	adds r0, r4, #0x0
	ldr r1, _08102D54 @ =0x09EF9A48
	ldr r2, _08102D58 @ =0x09EF9A20
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r1, r7, #0x0
	adds r1, #0x3C
	adds r1, r5, r1
	ldr r2, [sp, #0x000]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x08
	str r0, [r1, #0x00]
	adds r1, r7, #0x0
	adds r1, #0x40
	adds r1, r5, r1
	ldr r2, [sp, #0x004]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x08
	str r0, [r1, #0x00]
	ldr r0, _08102D5C @ =0x020358FC
	adds r5, r5, r0
	movs r0, #0x02
	str r0, [r5, #0x00]
	mov r2, r9
	mov r1, r8
	strh r2, [r1, #0x30]
	strh r2, [r1, #0x38]
	movs r0, #0x44
	add r8, r0
	mov r1, r8
	strh r2, [r1, #0x00]
	adds r6, #0x01
	lsls r6, r6, #0x10
	lsrs r3, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #0x04
	bgt _08102C1C
	b _08102AD6
_08102C1C:
	ldr r0, _08102D60 @ =0x09611AB8
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08102D64 @ =0x02035A30
	str r0, [r1, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _08102D68 @ =0x0905EAE8
	movs r1, #0xF0
	lsls r1, r1, #0x01
	bl func_080026A4
	ldr r1, _08102D6C @ =0x02035A34
	str r0, [r1, #0x00]
	ldr r0, _08102D70 @ =0x08F69BA4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08102D74 @ =0x02035A38
	str r0, [r1, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _08102D78 @ =0x0905ED36
	movs r1, #0xA0
	lsls r1, r1, #0x01
	bl func_080026A4
	ldr r1, _08102D7C @ =0x02035A3C
	str r0, [r1, #0x00]
	ldr r0, _08102D80 @ =0x09A3DA7C
	movs r1, #0x20
	bl func_08002A14
	ldr r5, _08102D84 @ =0x02035AE0
	str r0, [r5, #0x00]
	ldr r0, _08102D88 @ =0x099A3CE4
	movs r1, #0xE0
	lsls r1, r1, #0x01
	bl func_080026A4
	ldr r1, _08102D8C @ =0x02035ADC
	str r0, [r1, #0x00]
	ldr r4, _08102D90 @ =0x02035AE8
	ldr r1, _08102D94 @ =0x09EF99F8
	ldr r2, _08102D98 @ =0x09EF99D8
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, [r5, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r0, _08102D9C @ =0x09A3DB7C
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08102DA0 @ =0x02035A40
	str r0, [r1, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	ldr r4, _08102DA4 @ =0x02035A44
	movs r0, #0x90
	lsls r0, r0, #0x01
	bl func_08000918
	str r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065ACC
	ldr r4, _08102DA8 @ =0x02035A4C
	movs r0, #0xB4
	lsls r0, r0, #0x02
	bl func_08000918
	str r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065ACC
	ldr r0, _08102DAC @ =0x0908B1B4
	movs r1, #0x9A
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08102DB0 @ =0x02035A54
	str r0, [r1, #0x00]
	ldr r4, _08102DB4 @ =0x02035A58
	ldr r1, _08102DB8 @ =0x09EEA164
	ldr r2, _08102DBC @ =0x09EEA148
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	movs r3, #0x00
_08102D10:
	lsls r4, r3, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x02
	ldr r1, _08102DC0 @ =0x02035A70
	adds r0, r0, r1
	movs r1, #0x08
	bl func_08000E64
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r3, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x04
	ble _08102D10
	ldr r0, _08102DC4 @ =0x020358C8
	adds r0, #0x44
	movs r1, #0x0F
	strh r1, [r0, #0x00]
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08102D48: .4byte 0x00000FFF
_08102D4C: .4byte 0x09A3DB1C
_08102D50: .4byte 0x099A4B9A
_08102D54: .4byte 0x09EF9A48
_08102D58: .4byte 0x09EF9A20
_08102D5C: .4byte 0x020358FC
_08102D60: .4byte 0x09611AB8
_08102D64: .4byte 0x02035A30
_08102D68: .4byte 0x0905EAE8
_08102D6C: .4byte 0x02035A34
_08102D70: .4byte 0x08F69BA4
_08102D74: .4byte 0x02035A38
_08102D78: .4byte 0x0905ED36
_08102D7C: .4byte 0x02035A3C
_08102D80: .4byte 0x09A3DA7C
_08102D84: .4byte 0x02035AE0
_08102D88: .4byte 0x099A3CE4
_08102D8C: .4byte 0x02035ADC
_08102D90: .4byte 0x02035AE8
_08102D94: .4byte 0x09EF99F8
_08102D98: .4byte 0x09EF99D8
_08102D9C: .4byte 0x09A3DB7C
_08102DA0: .4byte 0x02035A40
_08102DA4: .4byte 0x02035A44
_08102DA8: .4byte 0x02035A4C
_08102DAC: .4byte 0x0908B1B4
_08102DB0: .4byte 0x02035A54
_08102DB4: .4byte 0x02035A58
_08102DB8: .4byte 0x09EEA164
_08102DBC: .4byte 0x09EEA148
_08102DC0: .4byte 0x02035A70
_08102DC4: .4byte 0x020358C8
.syntax divided
