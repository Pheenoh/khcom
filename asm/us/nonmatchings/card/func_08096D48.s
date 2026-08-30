.syntax unified
	.align 2, 0
	.global func_08096D48
	.thumb
	.thumb_func
	.type func_08096D48, %function
func_08096D48: @ 08096D48
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r5, #0x00
	ldr r0, _08096D60 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _08096D68
	ldr r1, _08096D64 @ =0x090360BC
	b _08096D6A
_08096D60: .4byte 0x02039BB0
_08096D64: .4byte 0x090360BC
_08096D68:
	ldr r1, _08096DA4 @ =0x09035DCC
_08096D6A:
	lsls r0, r2, #0x03
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldrh r1, [r0, #0x04]
	adds r0, r2, #0x0
	bl func_08096C38
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _08096DA8 @ =0x0000FFFF
	cmp r4, r0
	beq _08096D96
	ldr r6, _08096DAC @ =0x0203A8C0
_08096D84:
	bl func_08096CCC
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, r5
	adds r0, r0, r6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _08096D84
_08096D96:
	adds r0, r4, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08096DA4: .4byte 0x09035DCC
_08096DA8: .4byte 0x0000FFFF
_08096DAC: .4byte 0x0203A8C0
.syntax divided
