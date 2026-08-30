.syntax unified
	.align 2, 0
	.global mode_status_0
	.thumb
	.thumb_func
	.type mode_status_0, %function
mode_status_0: @ 080D7410
	push {r4, lr}
	bl func_08004D74
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x1E
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x02
	movs r1, #0x02
	bl func_080055C8
	movs r0, #0x03
	movs r1, #0x03
	bl func_080055C8
	ldr r1, _080D7494 @ =0x097FFB98
	movs r2, #0x84
	lsls r2, r2, #0x06
	movs r0, #0x03
	bl func_080050B8
	ldr r1, _080D7498 @ =0x0984B118
	movs r0, #0x03
	movs r2, #0xA0
	bl func_080050DC
	ldr r1, _080D749C @ =0x09848198
	movs r4, #0xA0
	lsls r4, r4, #0x03
	movs r0, #0x03
	adds r2, r4, #0x0
	bl func_0800510C
	ldr r0, _080D74A0 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D74A8
	ldr r1, _080D74A4 @ =0x09847C98
	movs r0, #0x02
	adds r2, r4, #0x0
	bl func_0800510C
	b _080D74B2
	.byte 0x00, 0x00
_080D7494: .4byte 0x097FFB98
_080D7498: .4byte 0x0984B118
_080D749C: .4byte 0x09848198
_080D74A0: .4byte 0x02039BB0
_080D74A4: .4byte 0x09847C98
_080D74A8:
	ldr r1, _080D74F8 @ =0x09847798
	movs r0, #0x02
	adds r2, r4, #0x0
	bl func_0800510C
_080D74B2:
	ldr r1, _080D74FC @ =0x09848B98
	movs r2, #0xA0
	lsls r2, r2, #0x03
	movs r0, #0x00
	bl func_0800510C
	movs r0, #0x00
	bl func_0800501C
	bl func_080D733C
	ldr r4, _080D7500 @ =0x02034EE0
	adds r0, r4, #0x0
	movs r1, #0x04
	bl func_08000E64
	ldr r1, _080D7504 @ =0x09EF4F08
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	ldr r1, _080D7508 @ =0x02034EF4
	str r0, [r1, #0x00]
	ldr r1, _080D750C @ =0x09EF4EF0
	adds r0, r4, #0x0
	movs r2, #0x00
	bl func_08000E14
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	pop {r4}
	pop {r0}
	bx r0
_080D74F8: .4byte 0x09847798
_080D74FC: .4byte 0x09848B98
_080D7500: .4byte 0x02034EE0
_080D7504: .4byte 0x09EF4F08
_080D7508: .4byte 0x02034EF4
_080D750C: .4byte 0x09EF4EF0
.syntax divided
