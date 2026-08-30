.syntax unified
	.align 2, 0
	.global func_08102DC8
	.thumb
	.thumb_func
	.type func_08102DC8, %function
func_08102DC8: @ 08102DC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #0x00
	ldr r7, _08102F00 @ =0x020358C8
	movs r1, #0x10
	adds r1, r1, r7
	mov r8, r1
_08102DD8:
	lsls r6, r0, #0x10
	asrs r6, r6, #0x10
	lsls r5, r6, #0x03
	adds r5, r5, r6
	lsls r5, r5, #0x03
	adds r4, r5, r7
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r4, #0x00]
	bl func_08002C10
	adds r0, r7, #0x4
	adds r0, r5, r0
	ldr r0, [r0, #0x00]
	bl func_080028C0
	adds r4, r7, #0x0
	adds r4, #0x0C
	adds r4, r5, r4
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r4, #0x00]
	bl func_08002C10
	add r5, r8
	ldr r0, [r5, #0x00]
	bl func_080028C0
	adds r6, #0x01
	lsls r6, r6, #0x10
	lsrs r0, r6, #0x10
	asrs r6, r6, #0x10
	cmp r6, #0x04
	ble _08102DD8
	ldr r4, _08102F04 @ =0x02035AE0
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r4, #0x00]
	bl func_08002C10
	ldr r0, _08102F08 @ =0x02035ADC
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r4, _08102F0C @ =0x02035A40
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r4, #0x00]
	bl func_08002C10
	ldr r4, _08102F10 @ =0x02035A44
	ldr r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _08102F14 @ =0x02035A4C
	ldr r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _08102F18 @ =0x02035A30
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r4, #0x00]
	bl func_08002C10
	ldr r0, _08102F1C @ =0x02035A34
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r4, _08102F20 @ =0x02035A38
	ldr r0, [r4, #0x00]
	ldrh r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r4, #0x00]
	bl func_08002C10
	ldr r0, _08102F24 @ =0x02035A3C
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _08102F28 @ =0x02035A54
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r0, #0x00
_08102ED6:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x02
	adds r0, r0, r4
	lsls r0, r0, #0x02
	ldr r1, _08102F2C @ =0x02035A70
	adds r0, r0, r1
	bl func_08000F0C
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x04
	ble _08102ED6
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08102F00: .4byte 0x020358C8
_08102F04: .4byte 0x02035AE0
_08102F08: .4byte 0x02035ADC
_08102F0C: .4byte 0x02035A40
_08102F10: .4byte 0x02035A44
_08102F14: .4byte 0x02035A4C
_08102F18: .4byte 0x02035A30
_08102F1C: .4byte 0x02035A34
_08102F20: .4byte 0x02035A38
_08102F24: .4byte 0x02035A3C
_08102F28: .4byte 0x02035A54
_08102F2C: .4byte 0x02035A70
.syntax divided
