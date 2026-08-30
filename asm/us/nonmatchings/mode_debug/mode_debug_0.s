.syntax unified
	.align 2, 0
	.global mode_debug_0
	.thumb
	.thumb_func
	.type mode_debug_0, %function
mode_debug_0: @ 0800AC34
	push {r4, lr}
	bl func_0811FFA4
	ldr r4, _0800AD1C @ =0x02034898
	movs r0, #0x24
	bl func_08000918
	str r0, [r4, #0x00]
	movs r0, #0x01
	movs r1, #0x10
	bl func_08006120
	bl func_0801CB44
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x0F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x02
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x80
	bl func_08005610
	movs r0, #0x01
	movs r1, #0x00
	bl func_080055EC
	ldr r1, _0800AD20 @ =0x08C72CE4
	ldr r2, _0800AD24 @ =0x00005B40
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _0800AD28 @ =0x08F683E4
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x01
	bl func_080050DC
	ldr r1, _0800AD2C @ =0x08EEEB84
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl func_0800510C
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x1F
	movs r1, #0x1F
	movs r2, #0x1F
	bl func_08005778
	movs r0, #0x00
	bl func_08004FC8
	movs r1, #0xA8
	lsls r1, r1, #0x07
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl func_0805FA8C
	ldr r1, _0800AD30 @ =0x08F68604
	movs r0, #0x00
	movs r2, #0x20
	movs r3, #0x0F
	bl func_0805FA60
	ldr r0, _0800AD34 @ =0x08950902
	movs r1, #0xB8
	lsls r1, r1, #0x02
	bl func_080026A4
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x04]
	ldr r0, _0800AD38 @ =0x08F685E4
	movs r1, #0x20
	bl func_08002A14
	adds r1, r0, #0x0
	ldr r0, [r4, #0x00]
	str r1, [r0, #0x08]
	adds r0, #0x0C
	ldr r1, _0800AD3C @ =0x09EDF774
	ldr r2, _0800AD40 @ =0x09EDF764
	bl func_08005968
	ldr r0, [r4, #0x00]
	adds r0, #0x0C
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r3, _0800AD44 @ =0x081283CC
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x02
	bl func_0805FCB0
	bl func_08007E50
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _0800AD4C
	ldr r3, _0800AD48 @ =0x081283E0
	b _0800AD58
	.byte 0x00, 0x00
_0800AD1C: .4byte 0x02034898
_0800AD20: .4byte 0x08C72CE4
_0800AD24: .4byte 0x00005B40
_0800AD28: .4byte 0x08F683E4
_0800AD2C: .4byte 0x08EEEB84
_0800AD30: .4byte 0x08F68604
_0800AD34: .4byte 0x08950902
_0800AD38: .4byte 0x08F685E4
_0800AD3C: .4byte 0x09EDF774
_0800AD40: .4byte 0x09EDF764
_0800AD44: .4byte 0x081283CC
_0800AD48: .4byte 0x081283E0
_0800AD4C:
	bl func_08007E50
	lsls r0, r0, #0x10
	cmp r0, #0x00
	ble _0800AD68
	ldr r3, _0800AD64 @ =0x081283F0
_0800AD58:
	movs r0, #0xA8
	movs r1, #0x96
	movs r2, #0x02
	bl func_0805FCB0
	b _0800AD74
_0800AD64: .4byte 0x081283F0
_0800AD68:
	ldr r3, _0800AD88 @ =0x08128400
	movs r0, #0x90
	movs r1, #0x96
	movs r2, #0x02
	bl func_0805FCB0
_0800AD74:
	ldr r2, _0800AD8C @ =0x02034898
	ldr r1, [r2, #0x00]
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r1, [r2, #0x00]
	movs r0, #0xFF
	strb r0, [r1, #0x01]
	pop {r4}
	pop {r0}
	bx r0
_0800AD88: .4byte 0x08128400
_0800AD8C: .4byte 0x02034898
.syntax divided
