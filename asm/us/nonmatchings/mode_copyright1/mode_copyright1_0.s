.syntax unified
	.align 2, 0
	.global mode_copyright1_0
	.thumb
	.thumb_func
	.type mode_copyright1_0, %function
mode_copyright1_0: @ 080D7014
	push {r4, lr}
	cmp r0, #0x00
	bne _080D7024
	ldr r1, _080D7020 @ =0x02034ED4
	movs r0, #0x01
	b _080D7028
_080D7020: .4byte 0x02034ED4
_080D7024:
	ldr r1, _080D70FC @ =0x02034ED4
	movs r0, #0x00
_080D7028:
	strb r0, [r1, #0x00]
	ldr r4, _080D7100 @ =0x02034ED8
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl SaveRepairHeader
	cmp r0, #0x01
	bne _080D705A
	strb r0, [r4, #0x00]
	bl SaveClearHeader
	bl SaveClearSystem
	movs r0, #0x00
	bl SaveClearFileLarge
	movs r0, #0x01
	bl SaveClearFileLarge
	movs r0, #0x00
	bl SaveClearFileSmall
	movs r0, #0x01
	bl SaveClearFileSmall
_080D705A:
	movs r0, #0x00
	bl SaveRepairFileLarge
	cmp r0, #0x01
	bne _080D706C
	strb r0, [r4, #0x00]
	movs r0, #0x00
	bl SaveClearFileLarge
_080D706C:
	movs r0, #0x01
	bl SaveRepairFileLarge
	cmp r0, #0x01
	bne _080D707E
	strb r0, [r4, #0x00]
	movs r0, #0x01
	bl SaveClearFileLarge
_080D707E:
	movs r0, #0x00
	bl SaveRepairFileSmall
	cmp r0, #0x01
	bne _080D7090
	strb r0, [r4, #0x00]
	movs r0, #0x00
	bl SaveClearFileSmall
_080D7090:
	movs r0, #0x01
	bl SaveRepairFileSmall
	cmp r0, #0x01
	bne _080D70A2
	strb r0, [r4, #0x00]
	movs r0, #0x01
	bl SaveClearFileSmall
_080D70A2:
	bl SaveRepairSystem
	cmp r0, #0x01
	bne _080D70B0
	strb r0, [r4, #0x00]
	bl SaveClearSystem
_080D70B0:
	movs r0, #0x00
	bl func_0811FE70
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	ldr r0, _080D70FC @ =0x02034ED4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D7114
	ldr r1, _080D7104 @ =0x09801DD8
	ldr r2, _080D7108 @ =0x00004FC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D710C @ =0x0984B298
	movs r2, #0xE0
	lsls r2, r2, #0x01
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080D7110 @ =0x09849098
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	b _080D7136
	.byte 0x00, 0x00
_080D70FC: .4byte 0x02034ED4
_080D7100: .4byte 0x02034ED8
_080D7104: .4byte 0x09801DD8
_080D7108: .4byte 0x00004FC0
_080D710C: .4byte 0x0984B298
_080D7110: .4byte 0x09849098
_080D7114:
	ldr r1, _080D714C @ =0x097DB5F8
	ldr r2, _080D7150 @ =0x00004FC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D7154 @ =0x0984AA38
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080D7158 @ =0x09841798
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
_080D7136:
	movs r0, #0x01
	movs r1, #0x43
	bl func_08006120
	ldr r1, _080D715C @ =0x02034ED6
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D714C: .4byte 0x097DB5F8
_080D7150: .4byte 0x00004FC0
_080D7154: .4byte 0x0984AA38
_080D7158: .4byte 0x09841798
_080D715C: .4byte 0x02034ED6
.syntax divided
