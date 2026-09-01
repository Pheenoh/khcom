.syntax unified
	.align 2, 0
	.global task_btl_prize_1
	.thumb
	.thumb_func
	.type task_btl_prize_1, %function
task_btl_prize_1: @ 08030DAC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	ldr r6, _08030E34 @ =0x02039B84
	ldr r3, [r6, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x06
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08030DD0
	b _08031240
_08030DD0:
	ldr r0, [r7, #0x30]
	cmp r0, #0x00
	beq _08030DD8
	b _08031258
_08030DD8:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _08030E8C
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r3, r1
	ldr r4, [r0, #0x00]
	adds r5, r7, #0x4
	cmp r4, #0x00
	beq _08030E00
	adds r2, r7, #0x0
	adds r2, #0x08
	adds r3, r7, #0x0
	adds r3, #0x0C
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl _call_via_r4
_08030E00:
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x20]
	adds r0, r0, r1
	str r0, [r7, #0x08]
	subs r1, #0x0F
	ldr r0, [r6, #0x00]
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r7, #0x20]
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801A8A4
	cmp r0, #0x01
	bcc _08030E42
	cmp r0, #0x02
	bhi _08030E38
	ldr r0, [r7, #0x3C]
	negs r0, r0
	str r0, [r7, #0x3C]
	b _08030E42
_08030E34: .4byte 0x02039B84
_08030E38:
	cmp r0, #0x04
	bhi _08030E42
	ldr r0, [r7, #0x40]
	negs r0, r0
	str r0, [r7, #0x40]
_08030E42:
	ldr r0, [r7, #0x00]
	ldr r1, [r7, #0x3C]
	adds r0, r0, r1
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x40]
	adds r0, r0, r1
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	ldr r2, [r7, #0x0C]
	cmp r0, r2
	ble _08030E84
	ldrh r1, [r7, #0x2C]
	ldr r0, _08030E80 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r7, #0x2C]
	str r2, [r7, #0x08]
	bl GetRandom
	ldr r1, [r7, #0x24]
	asrs r4, r1, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r1, r1, r4
	adds r1, #0x01
	bl __modsi3
	adds r4, r4, r0
	negs r4, r4
	str r4, [r7, #0x20]
	b _08030E8C
_08030E80: .4byte 0x0000FFFD
_08030E84:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x02
	orrs r0, r1
	strh r0, [r7, #0x2C]
_08030E8C:
	ldrh r1, [r7, #0x2C]
	movs r0, #0x10
	ands r0, r1
	mov r12, r1
	cmp r0, #0x00
	bne _08030E9A
	b _08031244
_08030E9A:
	movs r4, #0x00
	mov r9, r4
	ldr r3, _08030EF8 @ =0x02039B84
	ldr r5, [r3, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ldr r0, [sp, #0x000]
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r8, r3
	cmp r0, #0x00
	bne _08030EBE
	b _080310E4
_08030EBE:
	ldr r0, [r5, #0x7C]
	ldr r1, [r7, #0x00]
	ldr r0, [r0, #0x04]
	subs r2, r1, r0
	adds r5, r1, #0x0
	cmp r2, #0x00
	bge _08030ECE
	subs r2, r0, r5
_08030ECE:
	ldr r0, _08030EFC @ =0x02039B9C
	ldr r1, [r0, #0x00]
	ldr r1, [r1, #0x7C]
	ldr r4, [r1, #0x04]
	subs r1, r5, r4
	adds r6, r0, #0x0
	cmp r1, #0x00
	bge _08030EE0
	subs r1, r4, r5
_08030EE0:
	cmp r2, r1
	bne _08030F00
	movs r2, #0x80
	lsls r2, r2, #0x05
	ldr r0, [sp, #0x000]
	ands r0, r2
	movs r1, #0x00
	orrs r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, r0, #0x1F
	b _08030F08
_08030EF8: .4byte 0x02039B84
_08030EFC: .4byte 0x02039B9C
_08030F00:
	movs r0, #0x01
	cmp r2, r1
	bge _08030F08
	movs r0, #0x00
_08030F08:
	cmp r0, #0x00
	beq _08030FFC
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08030F20
	movs r4, #0x80
	lsls r4, r4, #0x09
_08030F20:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r1, r0, r5
	cmp r1, #0x00
	blt _08030F30
	cmp r1, r4
	blt _08030F36
	b _08030F7A
_08030F30:
	subs r0, r5, r0
	cmp r0, r4
	bge _08030F7A
_08030F36:
	asrs r4, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08030F4C
	cmp r1, r4
	blt _08030F52
	b _08030F7A
_08030F4C:
	subs r0, r0, r2
	cmp r0, r4
	bge _08030F7A
_08030F52:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08030F70
	ldr r0, _08030F6C @ =0x000031FF
	cmp r2, r0
	bgt _08030F68
	b _080310D8
_08030F68:
	b _08030F7A
	.byte 0x00, 0x00
_08030F6C: .4byte 0x000031FF
_08030F70:
	subs r1, r1, r0
	ldr r0, _08030FA0 @ =0x000031FF
	cmp r1, r0
	bgt _08030F7A
	b _080310D8
_08030F7A:
	mov r2, r8
	ldr r1, [r2, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08030F90
	movs r4, #0x80
	lsls r4, r4, #0x09
_08030F90:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r2, r0, r5
	cmp r2, #0x00
	blt _08030FA4
	cmp r2, r4
	blt _08030FAC
	b _08031154
_08030FA0: .4byte 0x000031FF
_08030FA4:
	subs r0, r5, r0
	cmp r0, r4
	blt _08030FAC
	b _08031154
_08030FAC:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08030FC4
	cmp r1, r4
	blt _08030FCC
	b _08031154
_08030FC4:
	subs r0, r0, r2
	cmp r0, r4
	blt _08030FCC
	b _08031154
_08030FCC:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08030FEC
	ldr r0, _08030FE8 @ =0x000031FF
	cmp r2, r0
	bgt _08030FE4
	b _0803115A
_08030FE4:
	b _08031154
	.byte 0x00, 0x00
_08030FE8: .4byte 0x000031FF
_08030FEC:
	subs r1, r1, r0
	ldr r0, _08030FF8 @ =0x000031FF
	cmp r1, r0
	ble _08030FF6
	b _08031154
_08030FF6:
	b _0803115A
_08030FF8: .4byte 0x000031FF
_08030FFC:
	mov r4, r8
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031012
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031012:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r1, r0, r5
	cmp r1, #0x00
	blt _08031022
	cmp r1, r4
	blt _08031028
	b _0803106C
_08031022:
	subs r0, r5, r0
	cmp r0, r4
	bge _0803106C
_08031028:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031040
	cmp r1, r4
	blt _08031046
	b _0803106C
_08031040:
	subs r0, r0, r2
	cmp r0, r4
	bge _0803106C
_08031046:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031064
	ldr r0, _08031060 @ =0x000031FF
	cmp r2, r0
	bgt _0803105E
	b _0803115A
_0803105E:
	b _0803106C
_08031060: .4byte 0x000031FF
_08031064:
	subs r1, r1, r0
	ldr r0, _08031090 @ =0x000031FF
	cmp r1, r0
	ble _0803115A
_0803106C:
	ldr r1, [r6, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _08031080
	movs r4, #0x80
	lsls r4, r4, #0x09
_08031080:
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x04]
	subs r2, r0, r5
	cmp r2, #0x00
	blt _08031094
	cmp r2, r4
	blt _0803109A
	b _08031154
_08031090: .4byte 0x000031FF
_08031094:
	subs r0, r5, r0
	cmp r0, r4
	bge _08031154
_0803109A:
	asrs r3, r4, #0x01
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _080310B0
	cmp r1, r3
	blt _080310B6
	b _08031154
_080310B0:
	subs r0, r0, r2
	cmp r0, r3
	bge _08031154
_080310B6:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _080310D0
	ldr r0, _080310CC @ =0x000031FF
	cmp r2, r0
	ble _080310D8
	b _08031154
_080310CC: .4byte 0x000031FF
_080310D0:
	subs r1, r1, r0
	ldr r0, _080310E0 @ =0x000031FF
	cmp r1, r0
	bgt _08031154
_080310D8:
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r7, #0x48]
	b _0803115A
_080310E0: .4byte 0x000031FF
_080310E4:
	adds r0, r5, #0x0
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	movs r4, #0xA0
	lsls r4, r4, #0x06
	cmp r0, #0x06
	bne _080310F6
	movs r4, #0x80
	lsls r4, r4, #0x09
_080310F6:
	ldr r0, [r5, #0x7C]
	ldr r3, [r0, #0x04]
	ldr r0, [r7, #0x00]
	subs r1, r3, r0
	cmp r1, #0x00
	blt _08031108
	cmp r1, r4
	blt _0803110E
	b _08031154
_08031108:
	subs r0, r0, r3
	cmp r0, r4
	bge _08031154
_0803110E:
	asrs r4, r4, #0x01
	mov r1, r8
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r2, [r0, #0x08]
	ldr r0, [r7, #0x04]
	subs r1, r2, r0
	cmp r1, #0x00
	blt _08031126
	cmp r1, r4
	blt _0803112C
	b _08031154
_08031126:
	subs r0, r0, r2
	cmp r0, r4
	bge _08031154
_0803112C:
	mov r2, r8
	ldr r0, [r2, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r0, [r0, #0x0C]
	ldr r1, [r7, #0x08]
	subs r2, r0, r1
	cmp r2, #0x00
	blt _08031148
	ldr r0, _08031144 @ =0x000031FF
	cmp r2, r0
	ble _08031150
	b _08031154
_08031144: .4byte 0x000031FF
_08031148:
	subs r1, r1, r0
	ldr r0, _08031194 @ =0x000031FF
	cmp r1, r0
	bgt _08031154
_08031150:
	movs r4, #0x01
	mov r9, r4
_08031154:
	mov r0, r9
	cmp r0, #0x00
	beq _08031210
_0803115A:
	movs r0, #0x6B
	bl m4aSongNumStart
	ldr r0, _08031198 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0803119C
	ldr r1, [r7, #0x48]
	ldrh r0, [r7, #0x3A]
	ldrh r2, [r1, #0x2C]
	adds r0, r0, r2
	strh r0, [r1, #0x2C]
	ldr r2, [r7, #0x48]
	movs r4, #0x2C
	ldsh r1, [r2, r4]
	ldrh r3, [r2, #0x2E]
	movs r4, #0x2E
	ldsh r0, [r2, r4]
	cmp r1, r0
	ble _080311C8
	strh r3, [r2, #0x2C]
	b _080311C8
_08031194: .4byte 0x000031FF
_08031198: .4byte 0x02039B84
_0803119C:
	ldr r1, [r7, #0x48]
	ldrh r0, [r7, #0x3A]
	ldrh r2, [r1, #0x2C]
	adds r0, r0, r2
	strh r0, [r1, #0x2C]
	ldr r2, [r7, #0x48]
	movs r4, #0x2C
	ldsh r1, [r2, r4]
	ldrh r3, [r2, #0x2E]
	movs r4, #0x2E
	ldsh r0, [r2, r4]
	cmp r1, r0
	ble _080311B8
	strh r3, [r2, #0x2C]
_080311B8:
	ldr r0, _08031208 @ =0x02039BB0
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldrh r2, [r7, #0x38]
	ldr r1, [r0, #0x00]
	adds r1, r1, r2
	str r1, [r0, #0x00]
_080311C8:
	movs r0, #0x01
	str r0, [r7, #0x30]
	movs r0, #0x00
	strh r0, [r7, #0x28]
	ldr r1, [r7, #0x48]
	ldr r0, [r1, #0x04]
	ldr r1, [r1, #0x08]
	ldr r2, [r7, #0x00]
	ldr r3, [r7, #0x04]
	bl GetAngle
	adds r1, r7, #0x0
	adds r1, #0x44
	strb r0, [r1, #0x00]
	ldrh r1, [r7, #0x2C]
	ldr r0, _0803120C @ =0x0000FFFD
	ands r0, r1
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r7, #0x2C]
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x06
	bl __umodsi3
	adds r0, #0x05
	adds r1, r7, #0x0
	adds r1, #0x2A
	strb r0, [r1, #0x00]
	b _080312DA
_08031208: .4byte 0x02039BB0
_0803120C: .4byte 0x0000FFFD
_08031210:
	movs r0, #0x08
	mov r2, r12
	ands r0, r2
	ldrh r2, [r7, #0x28]
	cmp r0, #0x00
	bne _08031254
	lsls r1, r2, #0x10
	movs r0, #0xB4
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _08031236
	movs r0, #0x03
	ands r0, r2
	cmp r0, #0x00
	bne _08031236
	movs r0, #0x01
	mov r4, r12
	eors r0, r4
	strh r0, [r7, #0x2C]
_08031236:
	lsls r1, r2, #0x10
	movs r0, #0xD2
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _08031254
_08031240:
	movs r0, #0x00
	b _080312DC
_08031244:
	movs r2, #0x28
	ldsh r0, [r7, r2]
	ldrh r2, [r7, #0x28]
	cmp r0, #0x0A
	ble _08031254
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r7, #0x2C]
_08031254:
	adds r0, r2, #0x1
	b _080312D8
_08031258:
	ldr r5, [r7, #0x48]
	ldr r6, _080312EC @ =0x08121400
	movs r4, #0x44
	adds r4, r4, r7
	mov r8, r4
	ldrb r4, [r4, #0x00]
	lsls r0, r4, #0x01
	adds r0, r0, r6
	movs r1, #0x00
	ldsh r2, [r0, r1]
	ldr r1, [r7, #0x34]
	lsls r0, r1, #0x05
	muls r0, r2
	asrs r0, r0, #0x08
	ldr r3, [r5, #0x04]
	adds r3, r3, r0
	adds r0, r4, #0x0
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r6
	movs r2, #0x00
	ldsh r0, [r0, r2]
	negs r0, r0
	lsls r1, r1, #0x04
	muls r0, r1
	asrs r0, r0, #0x08
	ldr r2, [r5, #0x08]
	adds r2, r2, r0
	ldrh r0, [r7, #0x28]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	lsls r0, r0, #0x08
	ldr r1, [r5, #0x0C]
	subs r1, r1, r0
	adds r0, r7, #0x0
	adds r0, #0x2A
	ldrb r0, [r0, #0x00]
	adds r4, r4, r0
	mov r0, r8
	strb r4, [r0, #0x00]
	ldr r0, [r7, #0x00]
	subs r3, r3, r0
	asrs r3, r3, #0x02
	adds r0, r0, r3
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x02
	adds r0, r0, r2
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x08]
	subs r1, r1, r0
	asrs r1, r1, #0x02
	adds r0, r0, r1
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x34]
	subs r0, #0x02
	str r0, [r7, #0x34]
	ldrh r1, [r7, #0x28]
	movs r2, #0x28
	ldsh r0, [r7, r2]
	cmp r0, #0x3C
	bgt _08031240
	adds r0, r1, #0x1
_080312D8:
	strh r0, [r7, #0x28]
_080312DA:
	movs r0, #0x01
_080312DC:
	add sp, #0x008
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080312EC: .4byte 0x08121400
.syntax divided
