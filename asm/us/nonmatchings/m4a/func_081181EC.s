.syntax unified
	.align 2, 0
	.global func_081181EC
	.thumb
	.thumb_func
	.type func_081181EC, %function
func_081181EC: @ 081181EC
	push {r4, r7, lr}
	add sp, #-0x040
	add r7, sp, #0x014
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	bl func_08118C34
	ldr r1, _0811820C @ =0x0203C7C4
	str r0, [r1, #0x00]
	ldr r0, _0811820C @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	cmp r1, #0x00
	bne _08118210
	movs r0, #0x00
	b _0811833C
	.byte 0x00, 0x00
_0811820C: .4byte 0x0203C7C4
_08118210:
	ldr r0, _08118240 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119654
	str r0, [r7, #0x28]
	ldr r0, [r7, #0x28]
	cmp r0, #0x00
	bne _08118224
	b _08118338
_08118224:
	ldr r0, _08118240 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119670
	ldr r1, [r7, #0x28]
	bl func_0811D1B0
	movs r0, #0x00
	str r0, [r7, #0x24]
_08118238:
	ldr r0, [r7, #0x24]
	cmp r0, #0x03
	ble _08118244
	b _08118338
_08118240: .4byte 0x0203C7C4
_08118244:
	ldr r0, [r7, #0x28]
	cmp r0, #0x01
	bne _081182A8
	ldr r0, _081182A4 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_081192B0
	adds r1, r0, #0x0
	adds r2, r7, #0x4
	adds r3, r7, #0x0
	adds r3, #0x14
	adds r0, r7, #0x0
	adds r0, #0x08
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0x18
	str r0, [sp, #0x004]
	movs r0, #0x00
	bl func_0811D408
	ldr r1, _081182A4 @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x08]
	ldr r4, [r7, #0x18]
	str r4, [sp, #0x000]
	ldr r4, [r7, #0x0C]
	str r4, [sp, #0x004]
	ldr r4, [r7, #0x1C]
	str r4, [sp, #0x008]
	ldr r4, [r7, #0x10]
	str r4, [sp, #0x00C]
	ldr r4, [r7, #0x20]
	str r4, [sp, #0x010]
	bl func_081192E8
	movs r0, #0x00
	bl func_0811D550
	ldr r0, _081182A4 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119480
	b _0811832A
	.byte 0x00, 0x00
_081182A4: .4byte 0x0203C7C4
_081182A8:
	ldr r0, _08118334 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_081192B0
	adds r1, r0, #0x0
	adds r2, r7, #0x4
	adds r3, r7, #0x0
	adds r3, #0x14
	adds r0, r7, #0x0
	adds r0, #0x08
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0x18
	str r0, [sp, #0x004]
	movs r0, #0x00
	bl func_0811D408
	ldr r0, _08118334 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_081192B0
	adds r1, r0, #0x0
	adds r2, r7, #0x0
	adds r2, #0x0C
	adds r3, r7, #0x0
	adds r3, #0x1C
	adds r0, r7, #0x0
	adds r0, #0x10
	str r0, [sp, #0x000]
	adds r0, r7, #0x0
	adds r0, #0x20
	str r0, [sp, #0x004]
	movs r0, #0x01
	bl func_0811D408
	ldr r1, _08118334 @ =0x0203C7C4
	ldr r0, [r1, #0x00]
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x08]
	ldr r4, [r7, #0x18]
	str r4, [sp, #0x000]
	ldr r4, [r7, #0x0C]
	str r4, [sp, #0x004]
	ldr r4, [r7, #0x1C]
	str r4, [sp, #0x008]
	ldr r4, [r7, #0x10]
	str r4, [sp, #0x00C]
	ldr r4, [r7, #0x20]
	str r4, [sp, #0x010]
	bl func_081192E8
	movs r0, #0x00
	bl func_0811D550
	movs r0, #0x01
	bl func_0811D550
	ldr r0, _08118334 @ =0x0203C7C4
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	bl func_08119480
_0811832A:
	ldr r0, [r7, #0x24]
	adds r1, r0, #0x1
	str r1, [r7, #0x24]
	b _08118238
	.byte 0x00, 0x00
_08118334: .4byte 0x0203C7C4
_08118338:
	movs r0, #0x01
	b _0811833C
_0811833C:
	add sp, #0x040
	pop {r4, r7}
	pop {r1}
	bx r1
.syntax divided
